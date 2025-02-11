/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <winapifamily.h>

#ifndef __NCRYPT_H__
#define __NCRYPT_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef WINAPI
#if defined(_ARM_)
#define WINAPI
#else
#define WINAPI __stdcall
#endif
#endif

#ifndef __SECSTATUS_DEFINED__
  typedef LONG SECURITY_STATUS;
#define __SECSTATUS_DEFINED__
#endif

#include <bcrypt.h>

#define NCRYPT_MAX_KEY_NAME_LENGTH 512
#define NCRYPT_MAX_ALG_ID_LENGTH 512

#define MS_KEY_STORAGE_PROVIDER L"Microsoft Software Key Storage Provider"
#define MS_SMART_CARD_KEY_STORAGE_PROVIDER L"Microsoft Smart Card Key Storage Provider"
#define MS_PLATFORM_KEY_STORAGE_PROVIDER L"Microsoft Platform Crypto Provider"

#define NCRYPT_RSA_ALGORITHM BCRYPT_RSA_ALGORITHM
#define NCRYPT_RSA_SIGN_ALGORITHM BCRYPT_RSA_SIGN_ALGORITHM
#define NCRYPT_DH_ALGORITHM BCRYPT_DH_ALGORITHM
#define NCRYPT_DSA_ALGORITHM BCRYPT_DSA_ALGORITHM
#define NCRYPT_MD2_ALGORITHM BCRYPT_MD2_ALGORITHM
#define NCRYPT_MD4_ALGORITHM BCRYPT_MD4_ALGORITHM
#define NCRYPT_MD5_ALGORITHM BCRYPT_MD5_ALGORITHM
#define NCRYPT_SHA1_ALGORITHM BCRYPT_SHA1_ALGORITHM
#define NCRYPT_SHA256_ALGORITHM BCRYPT_SHA256_ALGORITHM
#define NCRYPT_SHA384_ALGORITHM BCRYPT_SHA384_ALGORITHM
#define NCRYPT_SHA512_ALGORITHM BCRYPT_SHA512_ALGORITHM
#define NCRYPT_ECDSA_P256_ALGORITHM BCRYPT_ECDSA_P256_ALGORITHM
#define NCRYPT_ECDSA_P384_ALGORITHM BCRYPT_ECDSA_P384_ALGORITHM
#define NCRYPT_ECDSA_P521_ALGORITHM BCRYPT_ECDSA_P521_ALGORITHM
#define NCRYPT_ECDH_P256_ALGORITHM BCRYPT_ECDH_P256_ALGORITHM
#define NCRYPT_ECDH_P384_ALGORITHM BCRYPT_ECDH_P384_ALGORITHM
#define NCRYPT_ECDH_P521_ALGORITHM BCRYPT_ECDH_P521_ALGORITHM
#if NTDDI_VERSION >= 0x06020000
#define NCRYPT_AES_ALGORITHM BCRYPT_AES_ALGORITHM
#define NCRYPT_RC2_ALGORITHM BCRYPT_RC2_ALGORITHM
#define NCRYPT_3DES_ALGORITHM BCRYPT_3DES_ALGORITHM
#define NCRYPT_DES_ALGORITHM BCRYPT_DES_ALGORITHM
#define NCRYPT_DESX_ALGORITHM BCRYPT_DESX_ALGORITHM
#define NCRYPT_3DES_112_ALGORITHM BCRYPT_3DES_112_ALGORITHM
#define NCRYPT_SP800108_CTR_HMAC_ALGORITHM BCRYPT_SP800108_CTR_HMAC_ALGORITHM
#define NCRYPT_SP80056A_CONCAT_ALGORITHM BCRYPT_SP80056A_CONCAT_ALGORITHM
#define NCRYPT_PBKDF2_ALGORITHM BCRYPT_PBKDF2_ALGORITHM
#define NCRYPT_CAPI_KDF_ALGORITHM BCRYPT_CAPI_KDF_ALGORITHM
#endif

#define NCRYPT_KEY_STORAGE_ALGORITHM L"KEY_STORAGE"

#define NCRYPT_CIPHER_INTERFACE BCRYPT_CIPHER_INTERFACE
#define NCRYPT_HASH_INTERFACE BCRYPT_HASH_INTERFACE
#define NCRYPT_ASYMMETRIC_ENCRYPTION_INTERFACE BCRYPT_ASYMMETRIC_ENCRYPTION_INTERFACE
#define NCRYPT_SECRET_AGREEMENT_INTERFACE BCRYPT_SECRET_AGREEMENT_INTERFACE
#define NCRYPT_SIGNATURE_INTERFACE BCRYPT_SIGNATURE_INTERFACE
#if NTDDI_VERSION >= 0x06020000
#define NCRYPT_KEY_DERIVATION_INTERFACE BCRYPT_KEY_DERIVATION_INTERFACE
#endif

#define NCRYPT_KEY_STORAGE_INTERFACE 0x00010001
#define NCRYPT_SCHANNEL_INTERFACE 0x00010002
#define NCRYPT_SCHANNEL_SIGNATURE_INTERFACE 0x00010003
#if NTDDI_VERSION >= 0x06020000
#define NCRYPT_KEY_PROTECTION_INTERFACE 0x00010004
#endif

#define NCRYPT_RSA_ALGORITHM_GROUP NCRYPT_RSA_ALGORITHM
#define NCRYPT_DH_ALGORITHM_GROUP NCRYPT_DH_ALGORITHM
#define NCRYPT_DSA_ALGORITHM_GROUP NCRYPT_DSA_ALGORITHM
#define NCRYPT_ECDSA_ALGORITHM_GROUP L"ECDSA"
#define NCRYPT_ECDH_ALGORITHM_GROUP L"ECDH"

#if NTDDI_VERSION >= 0x06020000
#define NCRYPT_AES_ALGORITHM_GROUP NCRYPT_AES_ALGORITHM
#define NCRYPT_RC2_ALGORITHM_GROUP NCRYPT_RC2_ALGORITHM
#define NCRYPT_DES_ALGORITHM_GROUP L"DES"
#define NCRYPT_KEY_DERIVATION_GROUP L"KEY_DERIVATION"
#endif

#define NCRYPTBUFFER_VERSION 0

#define NCRYPTBUFFER_EMPTY 0
#define NCRYPTBUFFER_DATA 1
#define NCRYPTBUFFER_PROTECTION_DESCRIPTOR_STRING 3
#define NCRYPTBUFFER_PROTECTION_FLAGS 4

#define NCRYPTBUFFER_SSL_CLIENT_RANDOM 20
#define NCRYPTBUFFER_SSL_SERVER_RANDOM 21
#define NCRYPTBUFFER_SSL_HIGHEST_VERSION 22
#define NCRYPTBUFFER_SSL_CLEAR_KEY 23
#define NCRYPTBUFFER_SSL_KEY_ARG_DATA 24

#define NCRYPTBUFFER_PKCS_OID 40
#define NCRYPTBUFFER_PKCS_ALG_OID 41
#define NCRYPTBUFFER_PKCS_ALG_PARAM 42
#define NCRYPTBUFFER_PKCS_ALG_ID 43
#define NCRYPTBUFFER_PKCS_ATTRS 44
#define NCRYPTBUFFER_PKCS_KEY_NAME 45
#define NCRYPTBUFFER_PKCS_SECRET 46
#define NCRYPTBUFFER_CERT_BLOB 47

#define NCRYPT_NO_PADDING_FLAG 0x1
#define NCRYPT_PAD_PKCS1_FLAG 0x2
#define NCRYPT_PAD_OAEP_FLAG 0x4
#define NCRYPT_PAD_PSS_FLAG 0x8
#if NTDDI_VERSION >= 0x06020000
#define NCRYPT_PAD_CIPHER_FLAG 0x10

#define NCRYPT_CIPHER_NO_PADDING_FLAG 0x0
#define NCRYPT_CIPHER_BLOCK_PADDING_FLAG 0x1
#define NCRYPT_CIPHER_OTHER_PADDING_FLAG 0x2
#endif

#ifndef HCRYPTPROV_DEFINED
#define HCRYPTPROV_DEFINED
  typedef ULONG_PTR HCRYPTPROV;
  typedef ULONG_PTR HCRYPTKEY;
  typedef ULONG_PTR HCRYPTHASH;
#endif

  typedef LPVOID (WINAPI *PFN_NCRYPT_ALLOC) (SIZE_T cbSize);
  typedef VOID (WINAPI *PFN_NCRYPT_FREE) (LPVOID pv);

  typedef struct NCRYPT_ALLOC_PARA {
    DWORD cbSize;
    PFN_NCRYPT_ALLOC pfnAlloc;
    PFN_NCRYPT_FREE pfnFree;
  } NCRYPT_ALLOC_PARA;

  typedef BCryptBuffer NCryptBuffer;
  typedef BCryptBuffer *PNCryptBuffer;
  typedef BCryptBufferDesc NCryptBufferDesc;
  typedef BCryptBufferDesc *PNCryptBufferDesc;

  typedef ULONG_PTR NCRYPT_HANDLE;
  typedef ULONG_PTR NCRYPT_PROV_HANDLE;
  typedef ULONG_PTR NCRYPT_KEY_HANDLE;
  typedef ULONG_PTR NCRYPT_HASH_HANDLE;
  typedef ULONG_PTR NCRYPT_SECRET_HANDLE;

#if NTDDI_VERSION >= 0x06020000
  typedef struct _NCRYPT_CIPHER_PADDING_INFO {
    ULONG cbSize;
    DWORD dwFlags;
    PUCHAR pbIV;
    ULONG cbIV;
    PUCHAR pbOtherInfo;
    ULONG cbOtherInfo;
  } NCRYPT_CIPHER_PADDING_INFO,*PNCRYPT_CIPHER_PADDING_INFO;
#endif

#define NCRYPT_NO_KEY_VALIDATION BCRYPT_NO_KEY_VALIDATION
#define NCRYPT_MACHINE_KEY_FLAG 0x20
#define NCRYPT_SILENT_FLAG 0x40
#define NCRYPT_OVERWRITE_KEY_FLAG 0x80
#ifndef NCRYPT_WRITE_KEY_TO_LEGACY_STORE_FLAG
#define NCRYPT_WRITE_KEY_TO_LEGACY_STORE_FLAG 0x200
#endif
#ifndef NCRYPT_DO_NOT_FINALIZE_FLAG
#define NCRYPT_DO_NOT_FINALIZE_FLAG 0x400
#endif
#define NCRYPT_PERSIST_ONLY_FLAG 0x40000000
#define NCRYPT_PERSIST_FLAG 0x80000000
#define NCRYPT_REGISTER_NOTIFY_FLAG 0x1
#define NCRYPT_UNREGISTER_NOTIFY_FLAG 0x2

#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_DESKTOP) || _WIN32_WINNT >= 0x0A00
#define NCRYPT_CIPHER_OPERATION BCRYPT_CIPHER_OPERATION
#define NCRYPT_HASH_OPERATION BCRYPT_HASH_OPERATION
#define NCRYPT_ASYMMETRIC_ENCRYPTION_OPERATION BCRYPT_ASYMMETRIC_ENCRYPTION_OPERATION
#define NCRYPT_SECRET_AGREEMENT_OPERATION BCRYPT_SECRET_AGREEMENT_OPERATION
#define NCRYPT_SIGNATURE_OPERATION BCRYPT_SIGNATURE_OPERATION
#define NCRYPT_RNG_OPERATION BCRYPT_RNG_OPERATION
#if NTDDI_VERSION >= 0x06020000
#define NCRYPT_KEY_DERIVATION_OPERATION BCRYPT_KEY_DERIVATION_OPERATION
#endif

#define NCRYPT_MACHINE_KEY_FLAG 0x20

#define NCRYPT_MACHINE_KEY_FLAG 0x20
#define NCRYPT_SILENT_FLAG 0x40
#define NCRYPT_MACHINE_KEY_FLAG 0x20
#define NCRYPT_OVERWRITE_KEY_FLAG 0x80

  typedef struct _NCryptAlgorithmName {
    LPWSTR pszName;
    DWORD dwClass;
    DWORD dwAlgOperations;
    DWORD dwFlags;
  } NCryptAlgorithmName;

  typedef struct NCryptKeyName {
    LPWSTR pszName;
    LPWSTR pszAlgid;
    DWORD dwLegacyKeySpec;
    DWORD dwFlags;
  } NCryptKeyName;

  typedef struct NCryptProviderName {
    LPWSTR pszName;
    LPWSTR pszComment;
  } NCryptProviderName;

  SECURITY_STATUS WINAPI NCryptOpenStorageProvider (NCRYPT_PROV_HANDLE *phProvider, LPCWSTR pszProviderName, DWORD dwFlags);
  SECURITY_STATUS WINAPI NCryptEnumAlgorithms (NCRYPT_PROV_HANDLE hProvider, DWORD dwAlgOperations, DWORD *pdwAlgCount, NCryptAlgorithmName **ppAlgList, DWORD dwFlags);
  SECURITY_STATUS WINAPI NCryptIsAlgSupported (NCRYPT_PROV_HANDLE hProvider, LPCWSTR pszAlgId, DWORD dwFlags);
  SECURITY_STATUS WINAPI NCryptEnumKeys (NCRYPT_PROV_HANDLE hProvider, LPCWSTR pszScope, NCryptKeyName **ppKeyName, PVOID *ppEnumState, DWORD dwFlags);
  SECURITY_STATUS WINAPI NCryptEnumStorageProviders (DWORD *pdwProviderCount, NCryptProviderName **ppProviderList, DWORD dwFlags);
  SECURITY_STATUS WINAPI NCryptFreeBuffer (PVOID pvInput);
  SECURITY_STATUS WINAPI NCryptOpenKey (NCRYPT_PROV_HANDLE hProvider, NCRYPT_KEY_HANDLE *phKey, LPCWSTR pszKeyName, DWORD dwLegacyKeySpec, DWORD dwFlags);
  SECURITY_STATUS WINAPI NCryptCreatePersistedKey (NCRYPT_PROV_HANDLE hProvider, NCRYPT_KEY_HANDLE *phKey, LPCWSTR pszAlgId, LPCWSTR pszKeyName, DWORD dwLegacyKeySpec, DWORD dwFlags);

#define NCRYPT_NAME_PROPERTY L"Name"
#define NCRYPT_UNIQUE_NAME_PROPERTY L"Unique Name"
#define NCRYPT_ALGORITHM_PROPERTY L"Algorithm Name"
#define NCRYPT_LENGTH_PROPERTY L"Length"
#define NCRYPT_LENGTHS_PROPERTY L"Lengths"
#define NCRYPT_BLOCK_LENGTH_PROPERTY L"Block Length"
#if NTDDI_VERSION >= 0x06020000
#define NCRYPT_CHAINING_MODE_PROPERTY L"Chaining Mode"
#define NCRYPT_AUTH_TAG_LENGTH L"AuthTagLength"
#endif
#define NCRYPT_UI_POLICY_PROPERTY L"UI Policy"
#define NCRYPT_EXPORT_POLICY_PROPERTY L"Export Policy"
#define NCRYPT_WINDOW_HANDLE_PROPERTY L"HWND Handle"
#define NCRYPT_USE_CONTEXT_PROPERTY L"Use Context"
#define NCRYPT_IMPL_TYPE_PROPERTY L"Impl Type"
#define NCRYPT_KEY_USAGE_PROPERTY L"Key Usage"
#define NCRYPT_KEY_TYPE_PROPERTY L"Key Type"
#define NCRYPT_VERSION_PROPERTY L"Version"
#define NCRYPT_SECURITY_DESCR_SUPPORT_PROPERTY L"Security Descr Support"
#define NCRYPT_SECURITY_DESCR_PROPERTY L"Security Descr"
#define NCRYPT_USE_COUNT_ENABLED_PROPERTY L"Enabled Use Count"
#define NCRYPT_USE_COUNT_PROPERTY L"Use Count"
#define NCRYPT_LAST_MODIFIED_PROPERTY L"Modified"
#define NCRYPT_MAX_NAME_LENGTH_PROPERTY L"Max Name Length"
#define NCRYPT_ALGORITHM_GROUP_PROPERTY L"Algorithm Group"
#define NCRYPT_DH_PARAMETERS_PROPERTY BCRYPT_DH_PARAMETERS
#define NCRYPT_PROVIDER_HANDLE_PROPERTY L"Provider Handle"
#define NCRYPT_PIN_PROPERTY L"SmartCardPin"
#define NCRYPT_READER_PROPERTY L"SmartCardReader"
#define NCRYPT_SMARTCARD_GUID_PROPERTY L"SmartCardGuid"
#define NCRYPT_CERTIFICATE_PROPERTY L"SmartCardKeyCertificate"
#define NCRYPT_PIN_PROMPT_PROPERTY L"SmartCardPinPrompt"
#define NCRYPT_USER_CERTSTORE_PROPERTY L"SmartCardUserCertStore"
#define NCRYPT_ROOT_CERTSTORE_PROPERTY L"SmartcardRootCertStore"
#define NCRYPT_SECURE_PIN_PROPERTY L"SmartCardSecurePin"
#define NCRYPT_ASSOCIATED_ECDH_KEY L"SmartCardAssociatedECDHKey"
#define NCRYPT_SCARD_PIN_ID L"SmartCardPinId"
#define NCRYPT_SCARD_PIN_INFO L"SmartCardPinInfo"

#if NTDDI_VERSION >= 0x06020000
#define NCRYPT_READER_ICON_PROPERTY L"SmartCardReaderIcon"
#define NCRYPT_KDF_SECRET_VALUE L"KDFKeySecret"

#define NCRYPT_PCP_PLATFORM_TYPE_PROPERTY L"PCP_PLATFORM_TYPE"
#define NCRYPT_PCP_PROVIDER_VERSION_PROPERTY L"PCP_PROVIDER_VERSION"
#define NCRYPT_PCP_EKPUB_PROPERTY L"PCP_EKPUB"
#define NCRYPT_PCP_EKCERT_PROPERTY L"PCP_EKCERT"
#define NCRYPT_PCP_EKNVCERT_PROPERTY L"PCP_EKNVCERT"
#define NCRYPT_PCP_SRKPUB_PROPERTY L"PCP_SRKPUB"
#define NCRYPT_PCP_PCRTABLE_PROPERTY L"PCP_PCRTABLE"
#define NCRYPT_PCP_CHANGEPASSWORD_PROPERTY L"PCP_CHANGEPASSWORD"
#define NCRYPT_PCP_PASSWORD_REQUIRED_PROPERTY L"PCP_PASSWORD_REQUIRED"
#define NCRYPT_PCP_USAGEAUTH_PROPERTY L"PCP_USAGEAUTH"
#define NCRYPT_PCP_MIGRATIONPASSWORD_PROPERTY L"PCP_MIGRATIONPASSWORD"
#define NCRYPT_PCP_EXPORT_ALLOWED_PROPERTY L"PCP_EXPORT_ALLOWED"
#define NCRYPT_PCP_STORAGEPARENT_PROPERTY L"PCP_STORAGEPARENT"
#define NCRYPT_PCP_PROVIDERHANDLE_PROPERTY L"PCP_PROVIDERMHANDLE"
#define NCRYPT_PCP_PLATFORMHANDLE_PROPERTY L"PCP_PLATFORMHANDLE"
#define NCRYPT_PCP_PLATFORM_BINDING_PCRMASK_PROPERTY L"PCP_PLATFORM_BINDING_PCRMASK"
#define NCRYPT_PCP_PLATFORM_BINDING_PCRDIGESTLIST_PROPERTY L"PCP_PLATFORM_BINDING_PCRDIGESTLIST"
#define NCRYPT_PCP_PLATFORM_BINDING_PCRDIGEST_PROPERTY L"PCP_PLATFORM_BINDING_PCRDIGEST"
#define NCRYPT_PCP_KEY_USAGE_POLICY_PROPERTY L"PCP_KEY_USAGE_POLICY"
#define NCRYPT_PCP_TPM12_IDBINDING_PROPERTY L"PCP_TPM12_IDBINDING"
#define NCRYPT_PCP_TPM12_IDACTIVATION_PROPERTY L"PCP_TPM12_IDACTIVATION"
#define NCRYPT_PCP_KEYATTESTATION_PROPERTY L"PCP_TPM12_KEYATTESTATION"
#define NCRYPT_PCP_ALTERNATE_KEY_STORAGE_LOCATION_PROPERTY L"PCP_ALTERNATE_KEY_STORAGE_LOCATION"

#define NCRYPT_TPM12_PROVIDER (0x00010000)
#define NCRYPT_PCP_SIGNATURE_KEY (0x1)
#define NCRYPT_PCP_ENCRYPTION_KEY (0x2)
#define NCRYPT_PCP_GENERIC_KEY (NCRYPT_PCP_SIGNATURE_KEY | NCRYPT_PCP_ENCRYPTION_KEY)
#define NCRYPT_PCP_STORAGE_KEY (0x00000004)
#define NCRYPT_PCP_IDENTITY_KEY (0x00000008)
#endif

#if NTDDI_VERSION >= 0x06020000
#define NCRYPT_INITIALIZATION_VECTOR BCRYPT_INITIALIZATION_VECTOR
#endif

#define NCRYPT_MAX_PROPERTY_NAME 64

#define NCRYPT_MAX_PROPERTY_DATA 0x100000

#define NCRYPT_ALLOW_EXPORT_FLAG 0x1
#define NCRYPT_ALLOW_PLAINTEXT_EXPORT_FLAG 0x2
#define NCRYPT_ALLOW_ARCHIVING_FLAG 0x00000004
#define NCRYPT_ALLOW_PLAINTEXT_ARCHIVING_FLAG 0x00000008

#define NCRYPT_IMPL_HARDWARE_FLAG 0x1
#define NCRYPT_IMPL_SOFTWARE_FLAG 0x2
#define NCRYPT_IMPL_REMOVABLE_FLAG 0x00000008
#define NCRYPT_IMPL_HARDWARE_RNG_FLAG 0x00000010

#define NCRYPT_ALLOW_DECRYPT_FLAG 0x1
#define NCRYPT_ALLOW_SIGNING_FLAG 0x2
#define NCRYPT_ALLOW_KEY_AGREEMENT_FLAG 0x00000004
#define NCRYPT_ALLOW_ALL_USAGES 0x00ffffff

#define NCRYPT_UI_PROTECT_KEY_FLAG 0x1
#define NCRYPT_UI_FORCE_HIGH_PROTECTION_FLAG 0x2

#define NCRYPT_PERSIST_ONLY_FLAG 0x40000000
#define NCRYPT_PERSIST_FLAG 0x80000000
#define NCRYPT_PERSIST_ONLY_FLAG 0x40000000

typedef struct __NCRYPT_UI_POLICY {
    DWORD dwVersion;
    DWORD dwFlags;
    LPCWSTR pszCreationTitle;
    LPCWSTR pszFriendlyName;
    LPCWSTR pszDescription;
  } NCRYPT_UI_POLICY;

  typedef struct __NCRYPT_SUPPORTED_LENGTHS {
    DWORD dwMinLength;
    DWORD dwMaxLength;
    DWORD dwIncrement;
    DWORD dwDefaultLength;
  } NCRYPT_SUPPORTED_LENGTHS;

  SECURITY_STATUS WINAPI NCryptGetProperty (NCRYPT_HANDLE hObject, LPCWSTR pszProperty, PBYTE pbOutput, DWORD cbOutput, DWORD *pcbResult, DWORD dwFlags);
  SECURITY_STATUS WINAPI NCryptSetProperty (NCRYPT_HANDLE hObject, LPCWSTR pszProperty, PBYTE pbInput, DWORD cbInput, DWORD dwFlags);
  SECURITY_STATUS WINAPI NCryptFinalizeKey (NCRYPT_KEY_HANDLE hKey, DWORD dwFlags);
  SECURITY_STATUS WINAPI NCryptEncrypt (NCRYPT_KEY_HANDLE hKey, PBYTE pbInput, DWORD cbInput, VOID *pPaddingInfo, PBYTE pbOutput, DWORD cbOutput, DWORD *pcbResult, DWORD dwFlags);
  SECURITY_STATUS WINAPI NCryptDecrypt (NCRYPT_KEY_HANDLE hKey, PBYTE pbInput, DWORD cbInput, VOID *pPaddingInfo, PBYTE pbOutput, DWORD cbOutput, DWORD *pcbResult, DWORD dwFlags);

#if NTDDI_VERSION >= 0x06020000
  typedef struct _NCRYPT_KEY_BLOB_HEADER {
    ULONG cbSize;
    ULONG dwMagic;
    ULONG cbAlgName;
    ULONG cbKeyData;
  } NCRYPT_KEY_BLOB_HEADER,*PNCRYPT_KEY_BLOB_HEADER;

#define NCRYPT_CIPHER_KEY_BLOB_MAGIC 0x52485043
#define NCRYPT_PROTECTED_KEY_BLOB_MAGIC 0x4b545250

#define NCRYPT_CIPHER_KEY_BLOB L"CipherKeyBlob"
#define NCRYPT_PROTECTED_KEY_BLOB L"ProtectedKeyBlob"
#endif

#define NCRYPT_PKCS7_ENVELOPE_BLOB L"PKCS7_ENVELOPE"
#define NCRYPT_PKCS8_PRIVATE_KEY_BLOB L"PKCS8_PRIVATEKEY"
#define NCRYPT_OPAQUETRANSPORT_BLOB L"OpaqueTransport"

#define NCRYPT_MACHINE_KEY_FLAG 0x20
#define NCRYPT_EXPORT_LEGACY_FLAG 0x00000800

#define NCRYPT_REGISTER_NOTIFY_FLAG 0x1
#define NCRYPT_UNREGISTER_NOTIFY_FLAG 0x2
#define NCRYPT_MACHINE_KEY_FLAG 0x20

#define NCRYPT_KEY_STORAGE_INTERFACE_VERSION BCRYPT_MAKE_INTERFACE_VERSION (1, 0)
#define NCRYPT_KEY_STORAGE_INTERFACE_VERSION_2 BCRYPT_MAKE_INTERFACE_VERSION (2, 0)

  SECURITY_STATUS WINAPI NCryptImportKey (NCRYPT_PROV_HANDLE hProvider, NCRYPT_KEY_HANDLE hImportKey, LPCWSTR pszBlobType, NCryptBufferDesc *pParameterList, NCRYPT_KEY_HANDLE *phKey, PBYTE pbData, DWORD cbData, DWORD dwFlags);
  SECURITY_STATUS WINAPI NCryptExportKey (NCRYPT_KEY_HANDLE hKey, NCRYPT_KEY_HANDLE hExportKey, LPCWSTR pszBlobType, NCryptBufferDesc *pParameterList, PBYTE pbOutput, DWORD cbOutput, DWORD *pcbResult, DWORD dwFlags);
  SECURITY_STATUS WINAPI NCryptSignHash (NCRYPT_KEY_HANDLE hKey, VOID *pPaddingInfo, PBYTE pbHashValue, DWORD cbHashValue, PBYTE pbSignature, DWORD cbSignature, DWORD *pcbResult, DWORD dwFlags);
  SECURITY_STATUS WINAPI NCryptVerifySignature (NCRYPT_KEY_HANDLE hKey, VOID *pPaddingInfo, PBYTE pbHashValue, DWORD cbHashValue, PBYTE pbSignature, DWORD cbSignature, DWORD dwFlags);
  SECURITY_STATUS WINAPI NCryptDeleteKey (NCRYPT_KEY_HANDLE hKey, DWORD dwFlags);
  SECURITY_STATUS WINAPI NCryptFreeObject (NCRYPT_HANDLE hObject);
  WINBOOL WINAPI NCryptIsKeyHandle (NCRYPT_KEY_HANDLE hKey);
  SECURITY_STATUS WINAPI NCryptTranslateHandle (NCRYPT_PROV_HANDLE *phProvider, NCRYPT_KEY_HANDLE *phKey, HCRYPTPROV hLegacyProv, HCRYPTKEY hLegacyKey, DWORD dwLegacyKeySpec, DWORD dwFlags);
  SECURITY_STATUS WINAPI NCryptNotifyChangeKey (NCRYPT_PROV_HANDLE hProvider, HANDLE *phEvent, DWORD dwFlags);
  SECURITY_STATUS WINAPI NCryptSecretAgreement (NCRYPT_KEY_HANDLE hPrivKey, NCRYPT_KEY_HANDLE hPubKey, NCRYPT_SECRET_HANDLE *phAgreedSecret, DWORD dwFlags);
  SECURITY_STATUS WINAPI NCryptDeriveKey (NCRYPT_SECRET_HANDLE hSharedSecret, LPCWSTR pwszKDF, NCryptBufferDesc *pParameterList, PBYTE pbDerivedKey, DWORD cbDerivedKey, DWORD *pcbResult, ULONG dwFlags);
#if NTDDI_VERSION >= 0x06020000
  SECURITY_STATUS WINAPI NCryptKeyDerivation (NCRYPT_KEY_HANDLE hKey, NCryptBufferDesc *pParameterList, PUCHAR pbDerivedKey, DWORD cbDerivedKey, DWORD *pcbResult, ULONG dwFlags);
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif
