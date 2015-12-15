/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/

#include "qczmq.h"

///
//  Copy-construct to return the proper wrapped c types
QZcert::QZcert (zcert_t *self, QObject *qObjParent) : QObject (qObjParent)
{
    this->self = self;
}


///
//  Create and initialize a new certificate in memory
QZcert::QZcert (QObject *qObjParent) : QObject (qObjParent)
{
    this->self = zcert_new ();
}

///
//  Accepts public/secret key pair from caller
QZcert::QZcert (byte *publicKey, byte *secretKey, QObject *qObjParent) : QObject (qObjParent)
{
    this->self = zcert_new_from (publicKey, secretKey);
}

///
//  Load certificate from file
QZcert::QZcert (const QString &filename, QObject *qObjParent) : QObject (qObjParent)
{
    this->self = zcert_load (filename.toUtf8().data());
}

///
//  Destroy a certificate in memory
QZcert::~QZcert ()
{
    zcert_destroy (&self);
}

///
//  Return public part of key pair as 32-byte binary string
byte * QZcert::publicKey ()
{
    byte * rv = zcert_public_key (self);
    return rv;
}

///
//  Return secret part of key pair as 32-byte binary string
byte * QZcert::secretKey ()
{
    byte * rv = zcert_secret_key (self);
    return rv;
}

///
//  Return public part of key pair as Z85 armored string
const QString QZcert::publicTxt ()
{
    const QString rv = QString (zcert_public_txt (self));
    return rv;
}

///
//  Return secret part of key pair as Z85 armored string
const QString QZcert::secretTxt ()
{
    const QString rv = QString (zcert_secret_txt (self));
    return rv;
}

///
//  Set certificate metadata from formatted string.
void QZcert::setMeta (const QString &name, const QString &param)
{
    zcert_set_meta (self, name.toUtf8().data(), "%s", param.toUtf8().data());
    
}

///
//  Unset certificate metadata.
void QZcert::unsetMeta (const QString &name)
{
    zcert_unset_meta (self, name.toUtf8().data());
    
}

///
//  Get metadata value from certificate; if the metadata value doesn't
//  exist, returns NULL.                                              
const QString QZcert::meta (const QString &name)
{
    const QString rv = QString (zcert_meta (self, name.toUtf8().data()));
    return rv;
}

///
//  Get list of metadata fields from certificate. Caller is responsible for
//  destroying list. Caller should not modify the values of list items.    
QZlist * QZcert::metaKeys ()
{
    QZlist *rv = new QZlist (zcert_meta_keys (self));
    return rv;
}

///
//  Save full certificate (public + secret) to file for persistent storage  
//  This creates one public file and one secret file (filename + "_secret").
int QZcert::save (const QString &filename)
{
    int rv = zcert_save (self, filename.toUtf8().data());
    return rv;
}

///
//  Save public certificate only to file for persistent storage
int QZcert::savePublic (const QString &filename)
{
    int rv = zcert_save_public (self, filename.toUtf8().data());
    return rv;
}

///
//  Save secret certificate only to file for persistent storage
int QZcert::saveSecret (const QString &filename)
{
    int rv = zcert_save_secret (self, filename.toUtf8().data());
    return rv;
}

///
//  Apply certificate to socket, i.e. use for CURVE security on socket.
//  If certificate was loaded from public file, the secret key will be 
//  undefined, and this certificate will not work successfully.        
void QZcert::apply (void *zocket)
{
    zcert_apply (self, zocket);
    
}

///
//  Return copy of certificate; if certificate is NULL or we exhausted
//  heap memory, returns NULL.                                        
QZcert * QZcert::dup ()
{
    QZcert *rv = new QZcert (zcert_dup (self));
    return rv;
}

///
//  Return true if two certificates have the same keys
bool QZcert::eq (QZcert *compare)
{
    bool rv = zcert_eq (self, compare->self);
    return rv;
}

///
//  Print certificate contents to stdout
void QZcert::print ()
{
    zcert_print (self);
    
}

///
//  DEPRECATED as incompatible with centralized logging
//  Print certificate contents to open stream          
void QZcert::fprint (FILE *file)
{
    zcert_fprint (self, file);
    
}

///
//  Self test of this class
void QZcert::test (bool verbose)
{
    zcert_test (verbose);
    
}
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/