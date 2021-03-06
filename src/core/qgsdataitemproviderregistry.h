/***************************************************************************
  qgsdataitemproviderregistry.h
  --------------------------------------
  Date                 : March 2015
  Copyright            : (C) 2015 by Martin Dobias
  Email                : wonder dot sk at gmail dot com
 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSDATAITEMPROVIDERREGISTRY_H
#define QGSDATAITEMPROVIDERREGISTRY_H

#include "qgssingleton.h"

#include <QList>

class QgsDataItemProvider;

/**
 * This singleton class keeps a list of data item providers that may add items to the browser tree.
 * When created, it automatically adds providers from provider plugins (e.g. PostGIS, WMS, ...)
 *
 * @note added in 2.10
 */
class CORE_EXPORT QgsDataItemProviderRegistry : public QgsSingleton<QgsDataItemProviderRegistry>
{
  public:
    ~QgsDataItemProviderRegistry();

    //! Get list of available providers
    QList<QgsDataItemProvider*> providers() const { return mProviders; }

    //! Add a provider implementation. Takes ownership of the object.
    void addProvider( QgsDataItemProvider* provider );

    //! Remove provider implementation from the list (provider object is deleted)
    void removeProvider( QgsDataItemProvider* provider );

  private:
    QgsDataItemProviderRegistry();

    friend class QgsSingleton<QgsDataItemProviderRegistry>; // Let QgsSingleton access private constructor

    //! available providers. this class owns the pointers
    QList<QgsDataItemProvider*> mProviders;
};

#endif // QGSDATAITEMPROVIDERREGISTRY_H
