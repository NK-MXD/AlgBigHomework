#include "googleoauth.h"
#include "ui_googleoauth.h"
#include "googleoauth2wrapper.h"
#include <QFileDialog>
#include <QDesktopServices>
#include <QDebug>
#include <QTimer>

GoogleOAuth::GoogleOAuth(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GoogleOAuth)
{
    ui->setupUi(this);
    setWindowFlags(this->windowFlags() | Qt::Tool);

    //hide();
    connect(ui->LoginButton,SIGNAL(clicked()),
            this,SLOT(on_LoginButton_clicked));
//    connect(ui->actionRefersh_token,&QAction::triggered,
//            this,&MainWindow::onRefreshAccessToken);
//    ui->statusbar->showMessage("Ready");
    QTimer::singleShot(1000,this,&GoogleOAuth::initialOAuth);
}

GoogleOAuth::~GoogleOAuth()
{
    delete ui;
}

QString GoogleOAuth::accessToken()
{
    return m_strAccessToken;
}


void GoogleOAuth::on_LoginButton_clicked()
{
    if(!m_google){
        ui->textBrower->append(tr("Google auth not exist."));
        return;
    }
    m_google->grant();
}

void GoogleOAuth::initialOAuth()
{
    ui->textBrower->append(tr("Loading file ") + m_filename + "...");
    //! if initial is not first time execute
    if(!QFile::exists(m_filename)){
        QString fileName = QFileDialog::getOpenFileName(this, tr("Open OAuth setting File"),
                                                        m_filename,
                                                        tr("Json文件 (*json)"));
        m_filename = fileName.trimmed();
    }
    auto param = parseJson(m_filename);
    if(param.isEmpty()){
        ui->textBrower->append(tr("[Error]Loading error, check file is exist or content."));
        return;
    }
    ui->textBrower->append(tr("Loading sucess!"));
    ui->textBrower->append(param.toString());
    m_google = setupOAuth2(param,nullptr,this);
    connect(m_google,&QOAuth2AuthorizationCodeFlow::authorizeWithBrowser,
            this,&GoogleOAuth::onGoogleAuthorizeWithBrowser);
    connect(m_google,&QOAuth2AuthorizationCodeFlow::granted,
            this,&GoogleOAuth::onGoogleGranted);
}


void GoogleOAuth::onRefreshAccessToken()
{
    if(!m_google){
        ui->textBrower->append(tr("Google auth not exist."));
        return;
    }
    ui->textBrower->append(tr("Refresh token..."));
    m_google->refreshAccessToken();
}

void GoogleOAuth::onGoogleGranted()
{
    m_google->token();
    m_google->refreshToken();
    m_strAccessToken=m_google->token();
    ui->textBrower->append(m_strAccessToken);
    //ui->lineEdit_RefreshToken->setText(m_google->refreshToken());
    ui->textBrower->append(tr("Google authorized."));
    emit accessTokenObtained();
}

void GoogleOAuth::onGoogleAuthorizeWithBrowser(const QUrl &url)
{
    ui->textBrower->append(tr("Open with browser:") + url.toString());
    QDesktopServices::openUrl(url);
}
