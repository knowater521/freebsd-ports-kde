--- chromecast/browser/cast_browser_main_parts.cc.orig	2020-07-07 21:58:14 UTC
+++ chromecast/browser/cast_browser_main_parts.cc
@@ -75,7 +75,7 @@
 #include "ui/base/ui_base_switches.h"
 #include "ui/gl/gl_switches.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <fontconfig/fontconfig.h>
 #include <signal.h>
 #include <sys/prctl.h>
@@ -272,7 +272,7 @@ class CastViewsDelegate : public views::ViewsDelegate 
 
 #endif  // defined(USE_AURA)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 base::FilePath GetApplicationFontsDir() {
   std::unique_ptr<base::Environment> env(base::Environment::Create());
@@ -288,7 +288,7 @@ base::FilePath GetApplicationFontsDir() {
   }
 }
 
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 }  // namespace
 
@@ -317,7 +317,7 @@ const DefaultCommandLineSwitch kDefaultSwitches[] = {
     {cc::switches::kDisableThreadedAnimation, ""},
 #endif  // defined(OS_ANDROID)
 #endif  // BUILDFLAG(IS_CAST_AUDIO_ONLY)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #if defined(ARCH_CPU_X86_FAMILY)
     // This is needed for now to enable the x11 Ozone platform to work with
     // current Linux/NVidia OpenGL drivers.
@@ -327,7 +327,7 @@ const DefaultCommandLineSwitch kDefaultSwitches[] = {
     {switches::kEnableHardwareOverlays, "cast"},
 #endif
 #endif
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
     // It's better to start GPU process on demand. For example, for TV platforms
     // cast starts in background and can't render until TV switches to cast
     // input.
@@ -479,7 +479,7 @@ void CastBrowserMainParts::ToolkitInitialized() {
     views_delegate_ = std::make_unique<CastViewsDelegate>();
 #endif  // defined(USE_AURA)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::FilePath dir_font = GetApplicationFontsDir();
   const FcChar8 *dir_font_char8 = reinterpret_cast<const FcChar8*>(dir_font.value().data());
   if (!FcConfigAppFontAddDir(gfx::GetGlobalFontConfig(), dir_font_char8)) {
