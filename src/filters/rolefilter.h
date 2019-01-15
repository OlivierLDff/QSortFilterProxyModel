#ifndef ROLEFILTER_H
#define ROLEFILTER_H

#include "filter.h"
#include <qqmlsortfilterproxymodel_shared.h>

SFPM_NAMESPACE_START

class SFPM_API_ RoleFilter : public Filter
{
    Q_OBJECT
    Q_PROPERTY(QString roleName READ roleName WRITE setRoleName NOTIFY roleNameChanged)

public:
    using Filter::Filter;

    const QString& roleName() const;
    void setRoleName(const QString& roleName);

Q_SIGNALS:
    void roleNameChanged();

protected:
    QVariant sourceData(const QModelIndex &sourceIndex, const QQmlSortFilterProxyModel& proxyModel) const;

private:
    QString m_roleName;
};

SFPM_NAMESPACE_END

#endif // ROLEFILTER_H
