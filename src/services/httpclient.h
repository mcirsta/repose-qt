#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QObject>

#include "src/models/request.h"
#include "src/models/response.h"

class HttpClient : public QObject {
    Q_OBJECT
public:
    explicit HttpClient(QObject* parent = nullptr);

    void initiateRequest(RequestPtr request);
signals:
    void responseReceived(ResponsePtr response);
private slots:
    void onResponseReceived(QNetworkReply* reply);
    void sslErrors(QNetworkReply *reply, const QList<QSslError> & errors);

private:
    QNetworkAccessManager* m_networkManager;
    bool ignoreSslErrors;
};

#endif // HTTPCLIENT_H
