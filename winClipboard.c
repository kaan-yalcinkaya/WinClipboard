#include <windows.h>
#include "winClipboard.h"

wchar_t *winClipboardGet()
{
    if(!IsClipboardFormatAvailable(CF_UNICODETEXT) ||
        !OpenClipboard(NULL)) return NULL;
    const GLOBALHANDLE globalhandle = GetClipboardData(CF_UNICODETEXT);
    if(!globalhandle) {
        CloseClipboard();
        return NULL;
    }
    const SIZE_T size = GlobalSize(globalhandle);
    wchar_t *text = (wchar_t *)malloc(size);
    if(!text) {
        CloseClipboard();
        return NULL;
    }
    wcscpy_s(text, size, GlobalLock(globalhandle));
    GlobalUnlock(globalhandle);
    CloseClipboard();
    return text;
}
void winClipboardSet(const wchar_t *wstr)
{
    if(!wstr || !*wstr) return;
    const size_t len = (wcslen(wstr) + 1) * sizeof(wchar_t);
    const GLOBALHANDLE globalhandle = GlobalAlloc(GHND | GMEM_SHARE, len);
    if(!globalhandle) return;
    memcpy(GlobalLock(globalhandle), wstr, len);
    GlobalUnlock(globalhandle);
    if(!OpenClipboard(NULL)) {
        GlobalFree(globalhandle);
        return;
    }
    EmptyClipboard();
    SetClipboardData(CF_UNICODETEXT, globalhandle);
    CloseClipboard();  
}
void wstr_free(wchar_t *wstr)
{
    if (wstr) free(pwcs);
}
