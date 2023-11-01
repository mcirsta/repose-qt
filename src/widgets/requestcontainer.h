#ifndef REQUESTCONTAINER_H
#define REQUESTCONTAINER_H

#include "paramtable.h"

#include <QWidget>
#include <QTextEdit>

#include <src/models/rootstate.h>

namespace Ui {
class RequestContainer;
}

class RequestContainer : public QWidget {
    Q_OBJECT

public:
    explicit RequestContainer(RootState* rootState, QWidget* parent = nullptr);
    ~RequestContainer();

    QString body() { return m_requestEditor->toPlainText(); }
private slots:
    void onBinaryBodyOpenDiagButtonClicked();
    void onParamTabViewCurrentIndexChanged();
    void onBodyTabWidgetCurrentIndexChanged();
    void onBinaryBodyChanged();

private:
    void onActiveRequestChanged();

private:
    RootState* m_rootState;
    Ui::RequestContainer* ui;

    QTextEdit* m_requestEditor;
    ParamTable* m_paramsTable;
    ParamTable* m_headersTable;
    ParamTable* m_formDataTable;
    ParamTable* m_formUrlTable;
};

#endif // REQUESTCONTAINER_H
