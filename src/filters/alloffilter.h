#ifndef ALLOFFILTER_H
#define ALLOFFILTER_H

#include "filtercontainerfilter.h"
#include <qqmlsortfilterproxymodel_shared.h>

SFPM_NAMESPACE_START

class SFPM_API_ AllOfFilter : public FilterContainerFilter {
    Q_OBJECT

public:
    using FilterContainerFilter::FilterContainerFilter;

protected:
    bool filterRow(const QModelIndex& sourceIndex, const QQmlSortFilterProxyModel& proxyModel) const override;
};

SFPM_NAMESPACE_END

#endif // ALLOFFILTER_H
