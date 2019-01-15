#ifndef FILTERROLE_H
#define FILTERROLE_H

#include "singlerole.h"
#include "filters/filtercontainer.h"
#include <qqmlsortfilterproxymodel_shared.h>

SFPM_NAMESPACE_START

class SFPM_API_ FilterRole : public SingleRole, public FilterContainer
{
    Q_OBJECT
    Q_INTERFACES(SFPM_NAMESPACE::FilterContainer)
    Q_PROPERTY(QQmlListProperty<SFPM_NAMESPACE::Filter> filters READ filtersListProperty)
    Q_CLASSINFO("DefaultProperty", "filters")

public:
    using SingleRole::SingleRole;

private:
    void onFilterAppended(Filter* filter) override;
    void onFilterRemoved(Filter* filter) override;
    void onFiltersCleared() override;

    QVariant data(const QModelIndex& sourceIndex, const QQmlSortFilterProxyModel& proxyModel) override;
};

SFPM_NAMESPACE_END

#endif // FILTERROLE_H
