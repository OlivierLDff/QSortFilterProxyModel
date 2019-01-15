#ifndef INDEXSORTER_H
#define INDEXSORTER_H

#include "sorters/sorter.h"

class IndexSorter : public SFPM_NAMESPACE::Sorter
{
public:
    using SFPM_NAMESPACE::Sorter::Sorter;
    int compare(const QModelIndex& sourceLeft, const QModelIndex& sourceRight, const SFPM_NAMESPACE::QQmlSortFilterProxyModel& proxyModel) const override;
};

class ReverseIndexSorter : public SFPM_NAMESPACE::Sorter
{
public:
    using SFPM_NAMESPACE::Sorter::Sorter;
    int compare(const QModelIndex& sourceLeft, const QModelIndex& sourceRight, const SFPM_NAMESPACE::QQmlSortFilterProxyModel& proxyModel) const override;
};

#endif // INDEXSORTER_H
