#ifndef SWITCHROLE_H
#define SWITCHROLE_H

#include "singlerole.h"
#include "filters/filtercontainer.h"
#include <QtQml>
#include <qqmlsortfilterproxymodel_shared.h>

SFPM_NAMESPACE_START

class SFPM_API_ SwitchRoleAttached : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant value READ value WRITE setValue NOTIFY valueChanged)
public:
    SwitchRoleAttached(QObject* parent);

    QVariant value() const;
    void setValue(QVariant value);

Q_SIGNALS:
    void valueChanged();

private:
    QVariant m_value;
};

class SwitchRole : public SingleRole, public FilterContainer
{
    Q_OBJECT
    Q_INTERFACES(SFPM_NAMESPACE::FilterContainer)
    Q_PROPERTY(QString defaultRoleName READ defaultRoleName WRITE setDefaultRoleName NOTIFY defaultRoleNameChanged)
    Q_PROPERTY(QVariant defaultValue READ defaultValue WRITE setDefaultValue NOTIFY defaultValueChanged)
    Q_PROPERTY(QQmlListProperty<SFPM_NAMESPACE::Filter> filters READ filtersListProperty)
    Q_CLASSINFO("DefaultProperty", "filters")

public:
    using SingleRole::SingleRole;

    QString defaultRoleName() const;
    void setDefaultRoleName(const QString& defaultRoleName);

    QVariant defaultValue() const;
    void setDefaultValue(const QVariant& defaultValue);

    void proxyModelCompleted(const QQmlSortFilterProxyModel& proxyModel) override;

    static SwitchRoleAttached* qmlAttachedProperties(QObject* object);

Q_SIGNALS:
    void defaultRoleNameChanged();
    void defaultValueChanged();

private:
    QVariant data(const QModelIndex& sourceIndex, const QQmlSortFilterProxyModel& proxyModel) override;

    void onFilterAppended(Filter *filter) override;
    void onFilterRemoved(Filter *filter) override;
    void onFiltersCleared() override;

    QString m_defaultRoleName;
    QVariant m_defaultValue;
};

SFPM_NAMESPACE_END

QML_DECLARE_TYPEINFO(SFPM_NAMESPACE::SwitchRole, QML_HAS_ATTACHED_PROPERTIES)

#endif // SWITCHROLE_H
