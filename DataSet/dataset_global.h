#ifndef DATASET_GLOBAL_H
#define DATASET_GLOBAL_H

#include <QtCore/qglobal.h>


#if defined(DATASET_LIBRARY)
#  define DATASETSHARED_EXPORT Q_DECL_EXPORT
#else
#  define DATASETSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // DATASET_GLOBAL_H
