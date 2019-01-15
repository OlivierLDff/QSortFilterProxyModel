#ifndef FILTERCONTAINERFILTER_H
#define FILTERCONTAINERFILTER_H

#include "filter.h"
#include "filtercontainer.h"
#include <qqmlsortfilterproxymodel_shared.h>

SFPM_NAMESPACE_START

class SFPM_API_ FilterContainerFilter : public Filter, public FilterContainer {
    Q_OBJECT
    Q_INTERFACES(SFPM_NAMESPACE::FilterContainer)
    Q_PROPERTY(QQmlListProperty<SFPM_NAMESPACE::Filter> filters READ filtersListProperty NOTIFY filtersChanged)
    Q_CLASSINFO("DefaultProperty", "filters")

public:
    using Filter::Filter;

    void proxyModelCompleted(const QQmlSortFilterProxyModel& proxyModel) override;

Q_SIGNALS:
    void filtersChanged();

private:
    void onFilterAppended(Filter* filter) override;
    void onFilterRemoved(Filter* filter) override;
    void onFiltersCleared() override;
};

SFPM_NAMESPACE_END

#endif // FILTERCONTAINERFILTER_H
