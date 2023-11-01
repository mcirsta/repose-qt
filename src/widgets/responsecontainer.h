#ifndef RESPONSECONTAINER_H
#define RESPONSECONTAINER_H

#include <QWidget>
#include <QTextEdit>


#include <src/models/rootstate.h>
#include <src/services/httpclient.h>

namespace Ui {
class ResponseContainer;
}

// TODO: Store response bodies in /tmp

class ResponseContainer : public QWidget {
    Q_OBJECT

public:
    explicit ResponseContainer(RootState* rootState, HttpClient* httpClient, QWidget* parent = nullptr);
    ~ResponseContainer();
private slots:
    void onResponseReceived(ResponsePtr response);

private:
    void bindRequest();
    void bindResponse(ResponsePtr);

private:
    Ui::ResponseContainer* ui;
    RootState* m_rootState;
    HttpClient* m_httpClient;

    QTextEdit* m_prettyResponseEditor;
};

#endif // RESPONSECONTAINER_H
