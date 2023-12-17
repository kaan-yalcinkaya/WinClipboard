#ifndef WIN_CLIPBOARD_H
#define WIN_CLIPBOARD_H

#include <wchar.h>

extern wchar_t *winClipboardGet();
extern void winClipboardSet(const wchar_t *wstr);
extern void wstr_free(wchar_t *wstr);

#endif //WIN_CLIPBOARD_H
