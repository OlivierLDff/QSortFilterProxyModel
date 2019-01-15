#ifndef TESTROLES_H
#define TESTROLES_H

#include "proxyroles/singlerole.h"
#include <QVariant>

class StaticRole : public SFPM_NAMESPACE::SingleRole
{
    Q_OBJECT
    Q_PROPERTY(QVariant value READ value WRITE setValue NOTIFY valueChanged)
public:
    using SFPM_NAMESPACE::SingleRole::SingleRole;

    QVariant value() const;
    void setValue(const QVariant& value);

Q_SIGNALS:
    void valueChanged();

protected:

private:
    QVariant data(const QModelIndex& sourceIndex, const SFPM_NAMESPACE::QQmlSortFilterProxyModel& proxyModel) override;
    QVariant m_value;
};

class SourceIndexRole : public SFPM_NAMESPACE::SingleRole
{
public:
    using SFPM_NAMESPACE::SingleRole::SingleRole;

private:
    QVariant data(const QModelIndex& sourceIndex, const SFPM_NAMESPACE::QQmlSortFilterProxyModel& proxyModel) override;
};

class MultiRole : public SFPM_NAMESPACE::ProxyRole
{
public:
    using SFPM_NAMESPACE::ProxyRole::ProxyRole;

    QStringList names() override;

private:
    QVariant data(const QModelIndex &sourceIndex, const SFPM_NAMESPACE::QQmlSortFilterProxyModel &proxyModel, const QString &name) override;
};

#endif // TESTROLES_H
