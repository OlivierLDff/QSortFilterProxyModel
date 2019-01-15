#ifndef REGEXPROLE_H
#define REGEXPROLE_H

#include "proxyrole.h"
#include <QRegularExpression>
#include <qqmlsortfilterproxymodel_shared.h>

SFPM_NAMESPACE_START

class SFPM_API_ RegExpRole : public ProxyRole
{
    Q_OBJECT
    Q_PROPERTY(QString roleName READ roleName WRITE setRoleName NOTIFY roleNameChanged)
    Q_PROPERTY(QString pattern READ pattern WRITE setPattern NOTIFY patternChanged)
    Q_PROPERTY(Qt::CaseSensitivity caseSensitivity READ caseSensitivity WRITE setCaseSensitivity NOTIFY caseSensitivityChanged)

public:
    using ProxyRole::ProxyRole;

    QString roleName() const;
    void setRoleName(const QString& roleName);

    QString pattern() const;
    void setPattern(const QString& pattern);

    Qt::CaseSensitivity caseSensitivity() const;
    void setCaseSensitivity(Qt::CaseSensitivity caseSensitivity);

    QStringList names() override;

Q_SIGNALS:
    void roleNameChanged();
    void patternChanged();    
    void caseSensitivityChanged();

private:
    QString m_roleName;
    QRegularExpression m_regularExpression;
    QVariant data(const QModelIndex &sourceIndex, const QQmlSortFilterProxyModel &proxyModel, const QString &name) override;
};

SFPM_NAMESPACE_END

#endif // REGEXPROLE_H
