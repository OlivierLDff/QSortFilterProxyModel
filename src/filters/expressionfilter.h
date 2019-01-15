#ifndef EXPRESSIONFILTER_H
#define EXPRESSIONFILTER_H

#include "filter.h"
#include <QQmlScriptString>
#include <qqmlsortfilterproxymodel_shared.h>

class QQmlExpression;

SFPM_NAMESPACE_START

class SFPM_API_ ExpressionFilter : public Filter
{
    Q_OBJECT
    Q_PROPERTY(QQmlScriptString expression READ expression WRITE setExpression NOTIFY expressionChanged)

public:
    using Filter::Filter;

    const QQmlScriptString& expression() const;
    void setExpression(const QQmlScriptString& scriptString);

    void proxyModelCompleted(const QQmlSortFilterProxyModel& proxyModel) override;

protected:
    bool filterRow(const QModelIndex& sourceIndex, const QQmlSortFilterProxyModel& proxyModel) const override;

Q_SIGNALS:
    void expressionChanged();

private:
    void updateContext(const QQmlSortFilterProxyModel& proxyModel);
    void updateExpression();

    QQmlScriptString m_scriptString;
    QQmlExpression* m_expression = nullptr;
    QQmlContext* m_context = nullptr;
};

SFPM_NAMESPACE_END

#endif // EXPRESSIONFILTER_H
