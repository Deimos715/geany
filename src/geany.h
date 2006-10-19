/*
 *      geany.h - this file is part of Geany, a fast and lightweight IDE
 *
 *      Copyright 2006 Enrico Troeger <enrico.troeger@uvena.de>
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * $Id$
 */

#ifndef GEANY_H
#define GEANY_H

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "tm_tagmanager.h"


// for detailed description look in the documentation, things are not
// listed in the documentation should not be changed ;-)
#define GEANY_HOME_DIR					g_get_home_dir()
#define GEANY_FILEDEFS_SUBDIR			"filedefs"
#define GEANY_CODENAME					"Kintaro"
#define GEANY_HOMEPAGE					"http://geany.uvena.de/"
#define GEANY_MAX_TAGS_COUNT			1000
#define GEANY_CHECK_FILE_DELAY			30
#define GEANY_WORDCHARS					"_#&abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\\"
#define GEANY_MAX_WORD_LENGTH			192
#define GEANY_MAX_AUTOCOMPLETE_WORDS	30
#define GEANY_MAX_AUTOCOMPLETE_HEIGHT	10
#define GEANY_STRING_UNTITLED			_("untitled")
#define GEANY_MSGWIN_HEIGHT				208
#define GEANY_WINDOW_MINIMAL_WIDTH		620
#define GEANY_WINDOW_MINIMAL_HEIGHT		440
#define GEANY_WINDOW_DEFAULT_WIDTH		900
#define GEANY_WINDOW_DEFAULT_HEIGHT		600
// some default settings which are used at the very first start of Geany to fill configuration file
#define GEANY_DEFAULT_TOOLS_MAKE		"make"
#ifdef G_OS_WIN32
#define GEANY_DEFAULT_TOOLS_TERMINAL	"cmd.exe"
#else
#define GEANY_DEFAULT_TOOLS_TERMINAL	"xterm"
#endif
#define GEANY_DEFAULT_TOOLS_BROWSER		"mozilla"
#define GEANY_DEFAULT_TOOLS_PRINTCMD	"lpr"
#define GEANY_DEFAULT_TOOLS_GREP		"grep"
#define GEANY_DEFAULT_MRU_LENGTH		10
#define GEANY_DEFAULT_FONT_SYMBOL_LIST	"Sans 9"
#define GEANY_DEFAULT_FONT_MSG_WINDOW	"Sans 9"
#define GEANY_DEFAULT_FONT_EDITOR		"Monospace 10"



/* store some pointers and variables for frequently used widgets  */
typedef struct MyApp
{
	gint			 	 toolbar_icon_style;
	// 0:x, 1:y, 2:width, 3:height
	gint				 geometry[4];
	gboolean			 debug_mode;
	// represents the state at startup while opening session files
	gboolean			 opening_session_files;
	// represents the state when Geany is quitting completely
	gboolean			 quitting;
	gboolean			 ignore_callback;
	gboolean			 ignore_global_tags;
	gboolean			 toolbar_visible;
	gboolean			 sidebar_symbol_visible;
	gboolean			 sidebar_openfiles_visible;
	gboolean			 sidebar_visible;
	gboolean			 msgwindow_visible;
	gboolean			 fullscreen;
	gboolean			 beep_on_errors;
	gboolean			 switch_msgwin_pages;
	gboolean			 tab_order_ltr;
	gboolean			 show_markers_margin;
	gboolean			 show_linenumber_margin;
	gboolean			 brace_match_ltgt;
	gboolean			 main_window_realized;
	// I know, it is a bit confusing, but this line breaking is globally,
	// to change the default value at startup, I think
	gboolean			 pref_editor_line_breaking;
	gboolean			 pref_editor_use_auto_indention;
	gboolean			 pref_editor_use_indicators;
	gboolean			 pref_editor_show_white_space;
	gboolean			 pref_editor_show_indent_guide;
	gboolean			 pref_editor_show_line_endings;
	gboolean			 pref_editor_auto_close_xml_tags;
	gboolean			 pref_editor_auto_complete_constructs;
	gboolean			 pref_editor_folding;
	gint				 pref_editor_tab_width;
	gint				 pref_editor_default_encoding;
	gboolean			 pref_editor_new_line;
	gboolean			 pref_editor_replace_tabs;
	gboolean			 pref_editor_trail_space;
	gboolean			 pref_main_load_session;
	gboolean			 pref_main_save_winpos;
	gboolean			 pref_main_confirm_exit;
	gboolean			 pref_toolbar_show_search;
	gboolean			 pref_toolbar_show_goto;
	gboolean			 pref_toolbar_show_undo;
	gboolean			 pref_toolbar_show_compile;
	gboolean			 pref_toolbar_show_zoom;
	gboolean			 pref_toolbar_show_colour;
	gboolean			 pref_toolbar_show_fileops;
	gint				 tab_pos_editor;
	gint				 tab_pos_msgwin;
	gint				 tab_pos_sidebar;
	guint				 mru_length;
	gint				 autocompletion_max_height;
	gint				 long_line_type;
	gint				 long_line_column;
	gchar				*long_line_color;
	gchar				*pref_template_developer;
	gchar				*pref_template_company;
	gchar				*pref_template_mail;
	gchar				*pref_template_initial;
	gchar				*pref_template_version;
	gchar				*editor_font;
	gchar				*tagbar_font;
	gchar				*msgwin_font;
	gchar				*configdir;
	gchar				*datadir;
	gchar				*docdir;
	gchar				*custom_date_format;
	gchar				*tools_browser_cmd;
	gchar				*tools_make_cmd;
	gchar				*tools_term_cmd;
	gchar				*tools_print_cmd;
	gchar				*tools_grep_cmd;
	GtkIconSize			 toolbar_icon_size;
	GtkWidget			*toolbar;
	GtkWidget			*run_button;
	GtkWidget			*compile_button;
	GtkWidget			*compile_button_image;
	GtkWidget			*tagbar;
	GtkWidget			*treeview_notebook;
	GtkWidget			*notebook;
	GtkWidget			*statusbar;
	GtkWidget			*window;
	GtkWidget			*popup_menu;
	GtkWidget			*toolbar_menu;
	GtkWidget			*new_file_menu;
	GtkWidget			*menu_insert_include_item[2];
	GtkWidget			*popup_goto_items[3];
	GtkWidget			*popup_items[5];
	GtkWidget			*menu_copy_items[5];
	GtkWidget			*redo_items[3];
	GtkWidget			*undo_items[3];
	GtkWidget			*save_buttons[4];
	GtkWidget			*sensitive_buttons[37];
	GtkWidget			*open_colorsel;
	GtkWidget			*open_fontsel;
	GtkWidget			*open_filesel;
	GtkWidget			*save_filesel;
	GtkWidget			*prefs_dialog;
	GtkWidget			*default_tag_tree;
	const TMWorkspace	*tm_workspace;
	GQueue				*recent_queue;
} MyApp;

MyApp *app;


// small struct to track tag name and type together
typedef struct GeanySymbol
{
	gchar	*str;
	gint	 type;
	gint	 line;
} GeanySymbol;


enum
{
	GEANY_IMAGE_SMALL_CROSS,
	GEANY_IMAGE_LOGO,
	GEANY_IMAGE_COMPILE,
	GEANY_IMAGE_SAVE_ALL,
	GEANY_IMAGE_NEW_ARROW
};

enum
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

enum {
	KILOBYTE = 1024,
	MEGABYTE = (KILOBYTE*1024),
	GIGABYTE = (MEGABYTE*1024)
};

enum
{
	MSG_STATUS = 0, // force it to start at 0 to keep in sync with the notebook page numbers
	MSG_COMPILER,
	MSG_MESSAGE,
	MSG_SCRATCH,
	MSG_VTE,
	TREEVIEW_SYMBOL,
	TREEVIEW_OPENFILES
};


#endif
