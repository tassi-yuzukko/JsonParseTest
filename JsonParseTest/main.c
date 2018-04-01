#include <stdio.h>
#include <tchar.h>
#include <string.h>
#include <stdlib.h>

#include "Sample.h"
#include "parson.h"
#include "JsonDeserializer.h"

#define JSON_FILE_PATH "Sample.json"

int main(void)
{
	Sample sample = { 0 };
	int i;

	JSON_Value *root_value = json_parse_file(JSON_FILE_PATH);
	JSON_Object *root = json_object(root_value);

	JSON_Array *innerList;

	JSON_GET_STR(root, sample, testString);
	for (i = 0; i < JSON_GET_ARRAY_SIZE(root, sample, innerList); i++)
	{
	}

	innerList = json_object_dotget_array(root, "innerList");
	sample.innerList = malloc(sizeof(Inner)*json_array_get_count(innerList));

	{
		JSON_Array* list = JSON_GET_ARRAY(root, sample, innerList, sizeof(Inner));

		for (i = 0; i < json_array_get_count(innerList); i++)
		{
			JSON_Object* obj = json_array_get_object(innerList, i);
			JSON_GET_NUM(obj, sample.innerList[i], testInt);
		}
	}


	json_value_free(root_value);
	return 0;
}