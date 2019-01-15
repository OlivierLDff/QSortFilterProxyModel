#ifndef ROLESORTER_H
#define ROLESORTER_H

#include "sorter.h"
#include <qqmlsortfilterproxymodel_shared.h>

SFPM_NAMESPACE_START

class SFPM_API_ RoleSorter : public Sorter
{
    Q_OBJECT
    Q_PROPERTY(QString roleName READ roleName WRITE setRoleName NOTIFY roleNameChanged)

public:
    using Sorter::Sorter;

    const QString& roleName() const;
    void setRoleName(const QString& roleName);

Q_SIGNALS:
    void roleNameChanged();

protected:
    QPair<QVariant, QVariant> sourceData(const QModelIndex &sourceLeft, const QModelIndex& sourceRight, const QQmlSortFilterProxyModel& proxyModel) const;
    int compare(const QModelIndex& sourceLeft, const QModelIndex& sourceRight, const QQmlSortFilterProxyModel& proxyModel) const override;

private:
    QString m_roleName;
};

SFPM_NAMESPACE_END

#endif // ROLESORTER_H
