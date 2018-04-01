#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parson.h"

#define JSON_GET_STR(_json, _struct, _key)                       \
do{                                                                          \
   const char* str = json_object_dotget_string(_json, #_key);  \
   _struct._key = malloc(strlen(str));	\
   strncpy(_struct._key, str, strlen(str)); \
} while (0);                                                                \

#define JSON_GET_NUM(_json, _struct, _key)                  \
do {                                                         \
   _struct._key = json_object_dotget_number(_json, #_key); \
}while(0); 

#define JSON_GET_BOOL(_json, _struct, _key)                 \
do {                                                         \
   _struct._key = json_object_dotget_boolean(_json, #_key);    \
}while(0); 

#define JSON_GET_ARRAY_SIZE(_json, _struct, _key)                 \
	json_array_get_count(json_object_dotget_array(_json, #_key))

#define _JSON_GET_ARRAY(_json, _struct, _key, _keySize)	\
	({	\
		JSON_Array* ary = json_object_dotget_array(_json, #_key);	\
		_struct._key = malloc(_keySize * json_array_get_count(innerList));	\
		ary;	\
	})

// 引数にデリゲートがいる
#define JSON_GET_OBJECT
#define JSON_GET_ARRAY_NUM
#define JSON_GET_ARRAY_STR
#define JSON_GET_ARRAY_BOOL

// 引数にデリゲートがいる
#define JSON_GET_ARRAY_OBJECT