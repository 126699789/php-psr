
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "ext/spl/spl_exceptions.h"
#include "zend_API.h"
#include "zend_interfaces.h"

#include "php_psr.h"
#include "psr_simple_cache.h"

/* {{{ CacheException ------------------------------------------------------- */

PHP_PSR_API zend_class_entry * PsrSimpleCacheCacheException_ce_ptr;

static zend_always_inline void php_psr_register_PsrSimpleCacheCacheException(INIT_FUNC_ARGS)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Psr\\SimpleCache\\CacheException", NULL);
    PsrSimpleCacheCacheException_ce_ptr = zend_register_internal_interface(&ce);
}

/* }}} ---------------------------------------------------------------------- */
/* {{{ CacheInterface ------------------------------------------------------- */

PHP_PSR_API zend_class_entry * PsrSimpleCacheCacheInterface_ce_ptr;

static zend_function_entry PsrSimpleCacheCacheInterface_methods[] = {
    PHP_PSR_ABSTRACT_ME(PsrSimpleCacheCacheInterface, get)
    PHP_PSR_ABSTRACT_ME(PsrSimpleCacheCacheInterface, set)
    PHP_PSR_ABSTRACT_ME(PsrSimpleCacheCacheInterface, delete)
    PHP_PSR_ABSTRACT_ME(PsrSimpleCacheCacheInterface, clear)
    PHP_PSR_ABSTRACT_ME(PsrSimpleCacheCacheInterface, getMultiple)
    PHP_PSR_ABSTRACT_ME(PsrSimpleCacheCacheInterface, setMultiple)
    PHP_PSR_ABSTRACT_ME(PsrSimpleCacheCacheInterface, deleteMultiple)
    PHP_PSR_ABSTRACT_ME(PsrSimpleCacheCacheInterface, has)
    PHP_FE_END
};

static zend_always_inline void php_psr_register_PsrSimpleCacheCacheInterface(INIT_FUNC_ARGS)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Psr\\SimpleCache\\CacheInterface", PsrSimpleCacheCacheInterface_methods);
    PsrSimpleCacheCacheInterface_ce_ptr = zend_register_internal_interface(&ce);
}

/* }}} ---------------------------------------------------------------------- */
/* {{{ InvalidArgumentException --------------------------------------------- */

PHP_PSR_API zend_class_entry * PsrSimpleCacheInvalidArgumentException_ce_ptr;

static zend_always_inline void php_psr_register_PsrSimpleCacheInvalidArgumentException(INIT_FUNC_ARGS)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Psr\\SimpleCache\\InvalidArgumentException", NULL);
    PsrSimpleCacheInvalidArgumentException_ce_ptr = zend_register_internal_interface(&ce);
    zend_class_implements(PsrSimpleCacheInvalidArgumentException_ce_ptr, 1, PsrSimpleCacheCacheException_ce_ptr);
}

/* }}} ---------------------------------------------------------------------- */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(psr_simple_cache)
{
    php_psr_register_PsrSimpleCacheCacheException(INIT_FUNC_ARGS_PASSTHRU);
    php_psr_register_PsrSimpleCacheCacheInterface(INIT_FUNC_ARGS_PASSTHRU);
    php_psr_register_PsrSimpleCacheInvalidArgumentException(INIT_FUNC_ARGS_PASSTHRU);

    return SUCCESS;
}
/* }}} */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: fdm=marker
 * vim: et sw=4 ts=4
 */
