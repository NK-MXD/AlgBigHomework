#ifndef GOOGLEOAUTH_H
#define GOOGLEOAUTH_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui {
class GoogleOAuth;
}
class QOAuth2AuthorizationCodeFlow;
QT_END_NAMESPACE

class GoogleOAuth : public QDialog
{
    Q_OBJECT

public:
    explicit GoogleOAuth(QWidget *parent = nullptr);
    QString accessToken();
    ~GoogleOAuth();

signals:
    void accessTokenObtained();

private slots:
    void on_LoginButton_clicked();
    void initialOAuth();
    void onRefreshAccessToken();
    void onGoogleGranted();
    void onGoogleAuthorizeWithBrowser(const QUrl &url);

private:
    Ui::GoogleOAuth *ui;
    QOAuth2AuthorizationCodeFlow *m_google = nullptr;
    QString m_filename = "client_secret.json"; //default oauth parameter loading path需要放到工程目录下
    QString m_strAccessToken;
};

#endif // GOOGLEOAUTH_H
