#ifndef REQUEST_H
#define REQUEST_H

#include "paramtablemodel.h"
#include "response.h"
#include <QDateTime>
#include <QElapsedTimer>
#include <QNetworkReply>
#include <QObject>
#include <QSharedPointer>

class Response;

typedef QSharedPointer<Response> ResponsePtr;

class Request : public QObject {
public:
    enum class MainTab {
        Request,
        Response
    };

    enum class RequestAttributeSection {
        Params,
        Headers,
        Body
    };

    enum class RequestBody {
        None,
        Raw,
        Form,
        UrlEncoded,
        Binary
    };

    enum class ResponseAttributeType {
        Headers,
        Body
    };

    enum class ResponseBodyType {
        Pretty,
        Raw,
        Preview
    };

    Q_OBJECT
    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged)
    Q_PROPERTY(QString method READ method WRITE setMethod NOTIFY methodChanged)
    Q_PROPERTY(QString body READ body WRITE setBody NOTIFY bodyChanged)
    Q_PROPERTY(ParamTableModelPtr bodyForm READ bodyForm WRITE setBodyForm NOTIFY bodyFormChanged)
    Q_PROPERTY(ParamTableModelPtr bodyUrlEncoded READ bodyUrlEncoded WRITE setBodyUrlEncoded NOTIFY bodyUrlEncodedChanged)
    Q_PROPERTY(QString bodyBinary READ bodyBinary WRITE setBodyBinary NOTIFY bodyBinaryChanged)
    Q_PROPERTY(ParamTableModelPtr headers READ headers WRITE setHeaders NOTIFY headersChanged)
    Q_PROPERTY(ParamTableModelPtr params READ params WRITE setParams NOTIFY paramsChanged)
    Q_PROPERTY(ResponsePtr response READ response WRITE setResponse NOTIFY responseChanged)
    Q_PROPERTY(QElapsedTimer requestTimer READ requestTimer WRITE setRequestTimer NOTIFY requestTimerChanged)
    Q_PROPERTY(MainTab activeTab READ activeTab WRITE setActiveTab NOTIFY activeTabChanged)
    Q_PROPERTY(RequestAttributeSection activeSection READ activeSection WRITE setActiveSection NOTIFY activeSectionChanged)
    Q_PROPERTY(RequestBody activeBody READ activeBody WRITE setActiveBody NOTIFY activeBodyChanged)
    Q_PROPERTY(QString requestMode READ requestMode WRITE setRequestMode NOTIFY requestModeChanged)
    Q_PROPERTY(ResponseAttributeType activeResponseAttribute READ activeResponseAttribute WRITE setActiveResponseAttribute NOTIFY activeResponseAttributeChanged)
    Q_PROPERTY(ResponseBodyType activeResponseBodyType READ activeResponseBodyType WRITE setActiveResponseBodyType NOTIFY activeResponseBodyTypeChanged)
    Q_PROPERTY(bool loading READ loading WRITE setLoading NOTIFY loadingChanged)
    Q_PROPERTY(QNetworkReply* networkReply READ networkReply WRITE setNetworkReply NOTIFY networkReplyChanged)
public:
    explicit Request(QObject* parent = nullptr);

    const QString& method() const;
    void setMethod(const QString& newMethod);

    const QString& url() const;
    void setUrl(const QString& newUrl);

    const QString displayName();

    const QString& body() const;
    void setBody(const QString& newBody);

    ParamTableModelPtr params() const;
    void setParams(ParamTableModelPtr newParams);

    ParamTableModelPtr headers() const;
    void setHeaders(ParamTableModelPtr newHeaders);

    ResponsePtr response() const;
    void setResponse(ResponsePtr newResponse);

    const QElapsedTimer& requestTimer() const;
    void setRequestTimer(const QElapsedTimer& newRequestTimer);

    MainTab activeTab() const;
    void setActiveTab(MainTab newActiveTab);

    RequestAttributeSection activeSection() const;
    void setActiveSection(RequestAttributeSection newActiveSection);

    RequestBody activeBody() const;
    void setActiveBody(RequestBody newActiveBody);

    ResponseAttributeType activeResponseAttribute() const;
    void setActiveResponseAttribute(ResponseAttributeType newActiveResponseAttribute);

    ResponseBodyType activeResponseBodyType() const;
    void setActiveResponseBodyType(ResponseBodyType newActiveResponseBodyType);

    const QString& requestMode() const;
    void setRequestMode(const QString& newRequestMode);

    ParamTableModelPtr bodyForm() const;
    void setBodyForm(ParamTableModelPtr newBodyForm);

    ParamTableModelPtr bodyUrlEncoded() const;
    void setBodyUrlEncoded(ParamTableModelPtr newBodyUrlEncoded);

    const QString& bodyBinary() const;
    void setBodyBinary(const QString& newBodyBinary);

    bool loading() const;
    void setLoading(bool newLoading);

    QNetworkReply* networkReply() const;
    void setNetworkReply(QNetworkReply* newNetworkReply);

signals:
    void urlChanged();
    void methodChanged();
    void startRequestTimeChanged();
    void bodyChanged();
    void paramsChanged();
    void headersChanged();
    void responseChanged();
    void requestTimerChanged();
    void activeTabChanged();
    void activeSectionChanged();
    void activeBodyChanged();
    void activeResponseAttributeChanged();
    void activeResponseBodyTypeChanged();
    void requestModeChanged();
    void bodyFormChanged();
    void bodyUrlEncodedChanged();
    void bodyBinaryChanged();

    void loadingChanged();

    void networkReplyChanged();

private:
    QString m_url;
    QString m_method;
    QElapsedTimer m_requestTimer;
    QString m_body;
    ParamTableModelPtr m_params;
    ParamTableModelPtr m_headers;
    ResponsePtr m_response;
    MainTab m_activeTab;
    RequestAttributeSection m_activeSection;
    RequestBody m_activeBody;
    ResponseAttributeType m_activeResponseAttribute;
    ResponseBodyType m_activeResponseBodyType;
    QString m_requestMode;

    void updateContentType();
    ParamTableModelPtr m_bodyForm;
    ParamTableModelPtr m_bodyUrlEncoded;
    QString m_bodyBinary;

    void setContentTypeForBinaryBody();
    bool m_loading;

    QNetworkReply* m_networkReply;

private slots:
    void onUrlChanged();
};

typedef QSharedPointer<Request> RequestPtr;

Q_DECLARE_METATYPE(Request*)
Q_DECLARE_METATYPE(QSharedPointer<Request>)

#endif // REQUEST_H
