#ifndef VALUEFILTER_H
#define VALUEFILTER_H

#include "rolefilter.h"
#include <QVariant>
#include <qqmlsortfilterproxymodel_shared.h>
SFPM_NAMESPACE_START

class SFPM_API_ ValueFilter : public RoleFilter {
    Q_OBJECT
    Q_PROPERTY(QVariant value READ value WRITE setValue NOTIFY valueChanged)

public:
    using RoleFilter::RoleFilter;

    const QVariant& value() const;
    void setValue(const QVariant& value);

protected:
    bool filterRow(const QModelIndex &sourceIndex, const QQmlSortFilterProxyModel& proxyModel) const override;

Q_SIGNALS:
    void valueChanged();

private:
    QVariant m_value;
};

SFPM_NAMESPACE_END

#endif // VALUEFILTER_H
