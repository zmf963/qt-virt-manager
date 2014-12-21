#include "dns_widget.h"

DNS_Widget::DNS_Widget(QWidget *parent, QString tag) :
    _Checked_Widget(parent, tag)
{
    forwardPlainNames = new QCheckBox("forwardPlainNames", this);
    forwarder = new Forwarder(this);
    hosts = new Host_DNS(this);
    baseLayout->addWidget(forwardPlainNames);
    baseLayout->addWidget(forwarder);
    baseLayout->addWidget(hosts);
}

/* public slots */
QDomDocument DNS_Widget::getDataDocument() const
{
    QDomDocument doc;
    QDomElement _dns;
    _dns = doc.createElement("dns");
    _dns.setAttribute(
                "forwardPlainNames",
                (forwardPlainNames->isChecked())? "yes":"no");
    if ( forwarder->isUsed() ) {
        _dns.appendChild(
                    forwarder->getDataDocument());
    };
    if ( hosts->isUsed() ) {
        _dns.appendChild(
                    hosts->getDataDocument());
    };
    doc.appendChild(_dns);
    return doc;
}
