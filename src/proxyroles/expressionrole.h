#ifndef EXPRESSIONROLE_H
#define EXPRESSIONROLE_H

#include "singlerole.h"
#include <QQmlScriptString>
#include <qqmlsortfilterproxymodel_shared.h>

class QQmlExpression;

SFPM_NAMESPACE_START

class SFPM_API_ ExpressionRole : public SingleRole
{
    Q_OBJECT
    Q_PROPERTY(QQmlScriptString expression READ expression WRITE setExpression NOTIFY expressionChanged)

public:
    using SingleRole::SingleRole;

    const QQmlScriptString& expression() const;
    void setExpression(const QQmlScriptString& scriptString);

    void proxyModelCompleted(const QQmlSortFilterProxyModel& proxyModel) override;

Q_SIGNALS:
    void expressionChanged();

private:
    QVariant data(const QModelIndex& sourceIndex, const QQmlSortFilterProxyModel& proxyModel) override;
    void updateContext(const QQmlSortFilterProxyModel& proxyModel);
    void updateExpression();

    QQmlScriptString m_scriptString;
    QQmlExpression* m_expression = nullptr;
    QQmlContext* m_context = nullptr;
};

SFPM_NAMESPACE_END

#endif // EXPRESSIONROLE_H
