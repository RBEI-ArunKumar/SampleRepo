

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Tue May 18 16:11:40 2010
 */
/* Compiler settings for .\_BytComp.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __BytComp_h__
#define __BytComp_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDataProvider_FWD_DEFINED__
#define __IDataProvider_FWD_DEFINED__
typedef interface IDataProvider IDataProvider;
#endif 	/* __IDataProvider_FWD_DEFINED__ */


#ifndef __CDataProvider_FWD_DEFINED__
#define __CDataProvider_FWD_DEFINED__

#ifdef __cplusplus
typedef class CDataProvider CDataProvider;
#else
typedef struct CDataProvider CDataProvider;
#endif /* __cplusplus */

#endif 	/* __CDataProvider_FWD_DEFINED__ */


/* header files for imported files */
#include "prsht.h"
#include "mshtml.h"
#include "mshtmhst.h"
#include "exdisp.h"
#include "objsafe.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IDataProvider_INTERFACE_DEFINED__
#define __IDataProvider_INTERFACE_DEFINED__

/* interface IDataProvider */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDataProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A12EAEC2-2B64-470B-93AF-EFE0855DD3AC")
    IDataProvider : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSafeArray( 
            /* [retval][out] */ VARIANT *vtSafeArray) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetByteData( 
            /* [in] */ BYTE *bytArray) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetArray( 
            /* [in] */ BSTR bstrArray) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetThings( 
            /* [in] */ BYTE **ppThings) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetData( 
            /* [in] */ ULONG size,
            /* [size_is][in] */ BYTE *pData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDataProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDataProvider * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDataProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDataProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDataProvider * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDataProvider * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDataProvider * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDataProvider * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSafeArray )( 
            IDataProvider * This,
            /* [retval][out] */ VARIANT *vtSafeArray);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetByteData )( 
            IDataProvider * This,
            /* [in] */ BYTE *bytArray);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetArray )( 
            IDataProvider * This,
            /* [in] */ BSTR bstrArray);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetThings )( 
            IDataProvider * This,
            /* [in] */ BYTE **ppThings);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetData )( 
            IDataProvider * This,
            /* [in] */ ULONG size,
            /* [size_is][in] */ BYTE *pData);
        
        END_INTERFACE
    } IDataProviderVtbl;

    interface IDataProvider
    {
        CONST_VTBL struct IDataProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDataProvider_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDataProvider_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDataProvider_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDataProvider_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDataProvider_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDataProvider_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDataProvider_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDataProvider_GetSafeArray(This,vtSafeArray)	\
    (This)->lpVtbl -> GetSafeArray(This,vtSafeArray)

#define IDataProvider_SetByteData(This,bytArray)	\
    (This)->lpVtbl -> SetByteData(This,bytArray)

#define IDataProvider_SetArray(This,bstrArray)	\
    (This)->lpVtbl -> SetArray(This,bstrArray)

#define IDataProvider_SetThings(This,ppThings)	\
    (This)->lpVtbl -> SetThings(This,ppThings)

#define IDataProvider_SetData(This,size,pData)	\
    (This)->lpVtbl -> SetData(This,size,pData)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDataProvider_GetSafeArray_Proxy( 
    IDataProvider * This,
    /* [retval][out] */ VARIANT *vtSafeArray);


void __RPC_STUB IDataProvider_GetSafeArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDataProvider_SetByteData_Proxy( 
    IDataProvider * This,
    /* [in] */ BYTE *bytArray);


void __RPC_STUB IDataProvider_SetByteData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDataProvider_SetArray_Proxy( 
    IDataProvider * This,
    /* [in] */ BSTR bstrArray);


void __RPC_STUB IDataProvider_SetArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDataProvider_SetThings_Proxy( 
    IDataProvider * This,
    /* [in] */ BYTE **ppThings);


void __RPC_STUB IDataProvider_SetThings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDataProvider_SetData_Proxy( 
    IDataProvider * This,
    /* [in] */ ULONG size,
    /* [size_is][in] */ BYTE *pData);


void __RPC_STUB IDataProvider_SetData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDataProvider_INTERFACE_DEFINED__ */



#ifndef __BytComp_LIBRARY_DEFINED__
#define __BytComp_LIBRARY_DEFINED__

/* library BytComp */
/* [helpstring][uuid][version] */ 


EXTERN_C const IID LIBID_BytComp;

EXTERN_C const CLSID CLSID_CDataProvider;

#ifdef __cplusplus

class DECLSPEC_UUID("8816EAAA-91D5-4DCF-BA1A-DD699529D099")
CDataProvider;
#endif
#endif /* __BytComp_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


