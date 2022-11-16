#
#pragma region <imports>
#pragma region "export header imports"
#include <carbon/util/printfx.h>
#pragma endregion
#
#pragma region "platform-dependent imports"
#include <Windows.h>
#pragma endregion
#
#pragma region "platform-independent imports"
#include <assert.h>
#include <stdarg.h>
#pragma endregion
#
#pragma region "3rd-party imports"

#pragma endregion
#
#pragma region "shared imports"
#include <carbon/type/string.h>
#include <carbon/util/strings.h>
#include <carbon/io/io.h>
#pragma endregion
#
#pragma region "local imports"

#pragma endregion
#pragma endregion
#
#
struct NativeConsoleColorAttribute {
	const char* Name;
	int Background;
	int Foreground;
};


static struct NativeConsoleColorAttribute NativeConsoleColorAttributes[] = {
	{"AQUA", (BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY), (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY)},
	{"BLACK", (0), (0)},
	{"BLUE", BACKGROUND_BLUE, FOREGROUND_BLUE},
	{"GRAY", (BACKGROUND_INTENSITY), (FOREGROUND_INTENSITY)},
	{"GREEN", BACKGROUND_GREEN, FOREGROUND_GREEN},
	{"LIGHT_BLUE", (BACKGROUND_BLUE | BACKGROUND_INTENSITY), (FOREGROUND_BLUE | FOREGROUND_INTENSITY)},
	{"LIGHT_GRAY", (BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE), (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)},
	{"LIGHT_PURPLE", (BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY), (FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY)},
	{"LIGHT_RED", (BACKGROUND_INTENSITY | BACKGROUND_RED), (FOREGROUND_INTENSITY | FOREGROUND_RED)},
	{"LIGHT_YELLOW", (BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY), (FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY)},
	{"LIME", (BACKGROUND_GREEN | BACKGROUND_INTENSITY), (FOREGROUND_GREEN | FOREGROUND_INTENSITY)},
	{"PURPLE", (BACKGROUND_RED | BACKGROUND_BLUE), (FOREGROUND_RED | FOREGROUND_BLUE)},
	{"RED", BACKGROUND_RED, FOREGROUND_RED},
	{"TEAL", (BACKGROUND_GREEN | BACKGROUND_BLUE), (FOREGROUND_GREEN | FOREGROUND_BLUE)},
	{"YELLOW", (BACKGROUND_RED | BACKGROUND_GREEN), (FOREGROUND_RED | FOREGROUND_GREEN)},
	{"WHITE", (BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY), (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY)},
};


struct NativeConsoleColorAttribute* PickColorFromPalette(__in const char* string) {
	for (int csi = 0; csi < _countof(NativeConsoleColorAttributes); csi++) {
		struct NativeConsoleColorAttribute* o_attribute;

		o_attribute = &(NativeConsoleColorAttributes[csi]);

		for (int i = 0;; i++) {
			char c;

			if (string[i] == '\0') {
				if (o_attribute->Name[i] == '\0')
					return o_attribute;
				else {
					break;
				}
			}

			c = o_attribute->Name[i];

			if (c == '_' && o_attribute->Name[i] == '-')
				continue;

			c = tolower(c);

			if (tolower(string[i]) != c) {
				break;
			}
		}

		if (string_equals_ic(string, o_attribute->Name)) {
			return o_attribute;
		}
	}

	return NULL;
}


void cprintfx_intr(__in const char* format, __in va_list* args) {
#pragma region <locals>
	HANDLE                     h_console;
	CONSOLE_SCREEN_BUFFER_INFO o_csbi;
#pragma endregion


	h_console = GetStdHandle(STD_OUTPUT_HANDLE);

	if (NULL == h_console) {
		printf(TOSTRING(cprintfx) ": failed to get console output handle\n");

		abort();
	}

	if (!GetConsoleScreenBufferInfo(h_console, &o_csbi)) {
		printf(TOSTRING(cprintfx) ": failed to get console screen buffer\n");

		abort();
	}

	for (int cursor = 0; cursor < _MAX_STRING; cursor++) {
		char c;

		c = format[cursor];

		if (c == '\0')
			break;
		else if (c == '%') {
			char* pattern;
			int   pattern_begin;
			int   pattern_end;
			int   pattern_length;

			pattern_begin = pattern_end = cursor;

			while (cursor++ < _MAX_STRING) {
				c = format[cursor];

				if (c == '\0') {
					printf(TOSTRING(cprintfx) ": \"%s\" contains invalid pattern\n", format);

					abort();
				}

				if (c == 'd') {
					pattern_end = cursor;

					break;
				}
				
				if (c == 's') {
					pattern_end = cursor;

					if ((format[cursor + 1] == 't') || (format[cursor + 1] == 'w')) {
						cursor++;

						pattern_end++;
					}

					break;
				}
			}

			if (pattern_begin == pattern_end) {
				printf(TOSTRING(cprintfx) ": \"%s\" contains invalid pattern\n", format);

				abort();
			}

			pattern_length = (pattern_end - pattern_begin);

			pattern = (char*)malloc((pattern_length + 1) * sizeof(char));

			if (NULL == pattern) {
				printf(TOSTRING(cprintfx) ": failed to allocate memory for pattern in \"%s\"\n", pattern);

				abort();
			} else {
				strncpy(pattern, &(format[pattern_begin + 1]), pattern_length * sizeof(char));

				pattern[pattern_length] = '\0';
			}

			if (string_equals(pattern, "d")) {
				int num;

				//num = va_arg(args, int);

				//printf("%d", num);
			}
			else if (string_equals(pattern, "s")) {
				char* string;

				string = va_arg(*args, const char*);

				printf("%s", string);
			}
			else if (string_equals(pattern, "st")) {
				tchar_t* string;

				//string = va_arg(args, const tchar_t*);

				//tprintf(string);
			}
			else if (string_equals(pattern, "sw")) {
				wchar_t* string;

				//string = va_arg(args, const wchar_t*);

				//wprintf(string);
			}

			free(pattern);
		}
		else if (c == '<') {
			char* content;
			int   content_begin = -1;
			int   content_end = -1;
			int   content_length;
			int   intern_tag_count = 0;
			char* tag;
			int   tag_begin = -1;
			int   tag_end = -1;
			int   tag_length;
			char* value;
			int   value_begin = -1;
			int   value_end = -1;
			int   value_length;
			int   xml_begin = -1;
			int   xml_end = -1;
			int   xml_length;
			int   xml_c_begin = -1;
			int   xml_c_end = -1;
			int   xml_c_length;

			xml_begin = (cursor + 1);
			tag_begin = (cursor + 1);

			while (cursor++ < _MAX_STRING) {
				c = format[cursor];

				if (c == '\0') {
					printf(TOSTRING(cprintfx) ": \"%s\" contains invalid tag\n", format);

					abort();
				}

				if (c == ':') {
					if (tag_end != -1) {
						printf(TOSTRING(cprintfx) ": \"%s\" contains invalid tag\n", format);

						abort();
					}

					tag_end = cursor;
					value_begin = (cursor + 1);

					continue;
				}

				if (c == '>') {
					if (tag_end == -1) {
						tag_end = cursor;
					}

					value_end = cursor;
					xml_end = cursor;

					cursor++;

					break;
				}
			}

			tag_length = (tag_end - tag_begin);
			value_length = (value_end - value_begin);

			tag = (char*)malloc((tag_length + 1) * sizeof(char));

			if (NULL == tag) {
				printf(TOSTRING(cprintfx) ": failed to allocate memory for tag\n");

				abort();
			} else {
				strncpy(tag, &(format[tag_begin]), (tag_length * sizeof(char)));

				tag[tag_length] = '\0';
			}
			
			value = (char*)malloc((value_length + 1) * sizeof(char));

			if (NULL == value) {
				printf(TOSTRING(cprintfx) ": failed to allocate memory for tag value\n");

				abort();
			} else {
				strncpy(value, &(format[value_begin]), (value_length * sizeof(char)));

				value[value_length] = '\0';
			}

			xml_length = (xml_end - xml_begin);

			content_begin = cursor;

			while (cursor++ < _MAX_STRING) {
				c = format[cursor];

				if (c == '\0') {
					printf(TOSTRING(cprintfx) ": \"%s\" contains tag <%s> that is not closed with </%s>\n", format, tag, tag);

					abort();
				}

				if (c == '<') {
					if (format[cursor + 1] != '/') {
						intern_tag_count++;

						continue;
					}

					if (intern_tag_count > 0) {
						intern_tag_count--;

						continue;
					}

					content_end = cursor;
					xml_c_begin = (cursor + 1);

					continue;
				}

				if ((c == '>') && (xml_end != -1)) {
					xml_c_end = cursor;
					xml_c_length = (xml_c_end - xml_c_begin);

					if (_strnicmp(&(format[tag_begin]), &(format[xml_c_begin + 1]), tag_length) != 0) 
						continue;
					
					if (content_end == -1) {
						printf(TOSTRING(cprintfx) ": \"%s\" contains tag <%s> that is improperly closed\n", format, tag);

						abort();
					} else {
						break;
					}
				}
			}

			content_length = (content_end - content_begin);

			content = (char*)malloc((content_length + 1) * sizeof(char));

			if (NULL == content) {
				printf(TOSTRING(cprintfx) ": failed to allocate memory for data to print\n");

				abort();
			} else {
				strncpy(content, &(format[content_begin]), (content_length * sizeof(char)));

				content[content_length] = '\0';
			}

			if (string_equals_ic(tag, "background-color") || (string_equals_ic(tag, "color") || string_equals_ic(tag, "text-color"))) {
				struct NativeConsoleColorAttribute* o_attribute;
				WORD                                wAttributes = 0;

				o_attribute = PickColorFromPalette(value);

				if (NULL != o_attribute) {
					if (string_equals_ic(tag, "background-color")) {
						if (o_csbi.wAttributes & FOREGROUND_BLUE)
							wAttributes |= FOREGROUND_BLUE;
						if (o_csbi.wAttributes & FOREGROUND_GREEN)
							wAttributes |= FOREGROUND_GREEN;
						if (o_csbi.wAttributes & FOREGROUND_RED)
							wAttributes |= FOREGROUND_RED;
						if (o_csbi.wAttributes & FOREGROUND_INTENSITY)
							wAttributes |= FOREGROUND_INTENSITY;
						if (o_csbi.wAttributes & COMMON_LVB_UNDERSCORE)
							wAttributes |= COMMON_LVB_UNDERSCORE;

						wAttributes |= o_attribute->Background;
					}
					else if (string_equals_ic(tag, "color") || string_equals_ic(tag, "text-color")) {
						if (o_csbi.wAttributes & BACKGROUND_BLUE)
							wAttributes |= BACKGROUND_BLUE;
						if (o_csbi.wAttributes & BACKGROUND_GREEN)
							wAttributes |= BACKGROUND_GREEN;
						if (o_csbi.wAttributes & BACKGROUND_RED)
							wAttributes |= BACKGROUND_RED;
						if (o_csbi.wAttributes & BACKGROUND_INTENSITY)
							wAttributes |= BACKGROUND_INTENSITY;
						if (o_csbi.wAttributes & COMMON_LVB_UNDERSCORE)
							wAttributes |= COMMON_LVB_UNDERSCORE;

						wAttributes |= o_attribute->Foreground;
					}

					SetConsoleTextAttribute(h_console, wAttributes);
				}
			}
			else if (string_equals_ic(tag, "underline") || string_equals_ic(tag, "underscore")) {
				WORD wAttributes = 0;

				if (o_csbi.wAttributes & BACKGROUND_BLUE)
					wAttributes |= BACKGROUND_BLUE;
				if (o_csbi.wAttributes & BACKGROUND_GREEN)
					wAttributes |= BACKGROUND_GREEN;
				if (o_csbi.wAttributes & BACKGROUND_RED)
					wAttributes |= BACKGROUND_RED;
				if (o_csbi.wAttributes & BACKGROUND_INTENSITY)
					wAttributes |= BACKGROUND_INTENSITY;

				if (o_csbi.wAttributes & FOREGROUND_BLUE)
					wAttributes |= FOREGROUND_BLUE;
				if (o_csbi.wAttributes & FOREGROUND_GREEN)
					wAttributes |= FOREGROUND_GREEN;
				if (o_csbi.wAttributes & FOREGROUND_RED)
					wAttributes |= FOREGROUND_RED;
				if (o_csbi.wAttributes & FOREGROUND_INTENSITY)
					wAttributes |= FOREGROUND_INTENSITY;

				wAttributes |= COMMON_LVB_UNDERSCORE;

				SetConsoleTextAttribute(h_console, wAttributes);
			}

			cprintfx_intr(content, args);

			if (string_equals_ic(tag, "background-color") || (string_equals_ic(tag, "color") || string_equals_ic(tag, "text-color")) || (string_equals_ic(tag, "underline") || string_equals_ic(tag, "underscore"))) {
				SetConsoleTextAttribute(h_console, o_csbi.wAttributes);
			}

			free(content);
			free(value);
			free(tag);
		}
		else {
			printf("%c", c);
		}
	}
}


CBCEXPORT
void cprintfx(__in const char* format, __in_opt ...) {
	va_list args;

	va_start(args, format);

	cprintfx_intr(format, &args);

	va_end(args);
}

