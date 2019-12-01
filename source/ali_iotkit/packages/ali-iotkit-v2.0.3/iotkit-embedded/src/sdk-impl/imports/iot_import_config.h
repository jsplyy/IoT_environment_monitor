#ifndef __IOT_IMPORT_CONFIG_H__
#define __IOT_IMPORT_CONFIG_H__

#ifndef CONFIG_HTTP_AUTH_TIMEOUT
    #define CONFIG_HTTP_AUTH_TIMEOUT    (5 * 1000)
#endif

#ifndef CONFIG_MID_HTTP_TIMEOUT
    #define CONFIG_MID_HTTP_TIMEOUT     (5 * 1000)
#endif

#ifndef CONFIG_GUIDER_AUTH_TIMEOUT
    #define CONFIG_GUIDER_AUTH_TIMEOUT  (10 * 1000)
#endif

#ifndef CONFIG_COAP_AUTH_TIMEOUT
    #define CONFIG_COAP_AUTH_TIMEOUT    (10 * 1000)
#endif

#endif  /* __IOT_IMPORT_CONFIG_H__ */
