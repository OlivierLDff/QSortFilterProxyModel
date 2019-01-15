#ifndef ANYOFFILTER_H
#define ANYOFFILTER_H

#include "filtercontainerfilter.h"
#include <qqmlsortfilterproxymodel_shared.h>

SFPM_NAMESPACE_START

class SFPM_API_ AnyOfFilter : public FilterContainerFilter {
    Q_OBJECT

public:
    using FilterContainerFilter::FilterContainerFilter;

protected:
    bool filterRow(const QModelIndex& sourceIndex, const QQmlSortFilterProxyModel& proxyModel) const override;
};

SFPM_NAMESPACE_END

#endif // ANYOFFILTER_H
