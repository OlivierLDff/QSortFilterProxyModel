#ifndef INDEXFILTER_H
#define INDEXFILTER_H

#include "filter.h"
#include <QVariant>
#include <qqmlsortfilterproxymodel_shared.h>

SFPM_NAMESPACE_START

class SFPM_API_ IndexFilter: public Filter {
    Q_OBJECT
    Q_PROPERTY(QVariant minimumIndex READ minimumIndex WRITE setMinimumIndex NOTIFY minimumIndexChanged)
    Q_PROPERTY(QVariant maximumIndex READ maximumIndex WRITE setMaximumIndex NOTIFY maximumIndexChanged)

public:
    using Filter::Filter;

    const QVariant& minimumIndex() const;
    void setMinimumIndex(const QVariant& minimumIndex);

    const QVariant& maximumIndex() const;
    void setMaximumIndex(const QVariant& maximumIndex);

protected:
    bool filterRow(const QModelIndex& sourceIndex, const QQmlSortFilterProxyModel& proxyModel) const override;

Q_SIGNALS:
    void minimumIndexChanged();
    void maximumIndexChanged();

private:
    QVariant m_minimumIndex;
    QVariant m_maximumIndex;
};

SFPM_NAMESPACE_END

#endif // INDEXFILTER_H
