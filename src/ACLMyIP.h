
/*
 * $Id$
 *
 *
 * SQUID Web Proxy Cache          http://www.squid-cache.org/
 * ----------------------------------------------------------
 *
 *  Squid is the result of efforts by numerous individuals from
 *  the Internet community; see the CONTRIBUTORS file for full
 *  details.   Many organizations have provided support for Squid's
 *  development; see the SPONSORS file for full details.  Squid is
 *  Copyrighted (C) 2001 by the Regents of the University of
 *  California; see the COPYRIGHT file for full details.  Squid
 *  incorporates software developed and/or copyrighted by other
 *  sources; see the CREDITS file for full details.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
 *
 *
 * Copyright (c) 2003, Robert Collins <robertc@squid-cache.org>
 */

#ifndef SQUID_ACLMYIP_H
#define SQUID_ACLMYIP_H
#include "ACLIP.h"

class ACLMyIP : public ACLIP
{

public:
    void *operator new(size_t);
    void operator delete(void *);
    virtual void deleteSelf() const;
    static ACLMyIP const &RegistryEntry();

    virtual char const *typeString() const;
    virtual squid_acl aclType() const { return ACL_DERIVED;}

    virtual int match(ACLChecklist *checklist);
    virtual ACL *clone()const;

private:
    static MemPool *Pool;
    static Prototype RegistryProtoype;
    static ACLMyIP RegistryEntry_;
};

#endif /* SQUID_ACLMYIP_H */
