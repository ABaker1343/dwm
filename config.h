/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 4;        /* border pixel of windows */
static const unsigned int snap      = 16;       /* snap pixel */
static const unsigned int gappx     = 12;        /* size of the gaps (from fullgaps patch)*/
static const int showbar            = 0;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "UbuntuMonoLigaturized:size=18" };
static const char dmenufont[]       = "UbuntuMonoLigaturized:size=18";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_blue[]        = "#3399ff";
static const char col_off_white[]   = "#d2dbe4";
static const char col_dark_blue[]   = "#15416e";

#include "/home/alex/.cache/wal/colors-wal-dwm.h"
/*
static const char *colors[][3]      = {
	//               fg         bg         border
	[SchemeNorm] = { col_off_white, col_blue, col_gray1 },
	[SchemeSel]  = { col_off_white, col_blue, col_blue },
};

*/

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *firefoxcmd[] = { "firefox", NULL };
static const char *discordcmd[] = { "discord", NULL };
static const char *spotifycmd[] = { "spotify", NULL };
static const char *flameshotcmd[] = {"flameshot", "gui", NULL };
static const char *steamcmd[] = { "steam", NULL };
static const char *firefox_privatecmd[] = { "firefox", "--private", NULL};
static const char *spotify_play_pause_cmd[] = { "playerctl", "-p", "spotify", "play-pause", NULL};
static const char *spotify_next_cmd[] = { "playerctl", "-p", "spotify", "next", NULL};
static const char *spotify_prev_cmd[] = { "playerctl", "-p", "spotify", "previous", NULL};
static const char *volume_down_cmd[] = {"pactl", "set-sink-volume", "@DEFAULT_SINK@", "-5%", NULL};
static const char *volume_up_cmd[] = {"pactl", "set-sink-volume", "@DEFAULT_SINK@", "+5%", NULL};
static const char *pavucontrol_cmd[] = { "pavucontrol", NULL };
static const char *ranger_cmd[] = {"st", "-e", "ranger", "/home/alex", NULL };
static const char *dmenu_sound_select[] = {"/home/alex/.source/dwm/soundSelect.sh", NULL};

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_b,      spawn,          {.v = firefoxcmd } },
    { MODKEY|ShiftMask,             XK_p,      spawn,          {.v = firefox_privatecmd } },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          {.v = spotifycmd } },
	{ MODKEY|ShiftMask,             XK_d,      spawn,          {.v = discordcmd } },
    { MODKEY|ShiftMask,             XK_g,      spawn,          {.v = steamcmd } },
    { MODKEY|ShiftMask,             XK_a,      spawn,          {.v = dmenu_sound_select } },
    { MODKEY|ShiftMask,             XK_r,      spawn,          {.v = ranger_cmd } },
    { 0,                            XK_Print,  spawn,          {.v = flameshotcmd } },
    { MODKEY,                       XK_F6,     spawn,          {.v = spotify_play_pause_cmd } },
    { MODKEY,                       XK_F7,     spawn,          {.v = spotify_next_cmd } },
    { MODKEY,                       XK_F5,     spawn,          {.v = spotify_prev_cmd } },
    { MODKEY,                       XK_F2,     spawn,          {.v = volume_down_cmd } },
    { MODKEY,                       XK_F3,     spawn,          {.v = volume_up_cmd } },
    { MODKEY,                       XK_F10,    spawn,          SHCMD("transset-df -a") },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_Right,  focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_Left,   focusstack,     {.i = -1 } },
//	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
//	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_s,      setlayout,      {.v = &layouts[2]} },
    { MODKEY,                       XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY|ControlMask,           XK_Left,  focusmon,       {.i = -1 } },
	{ MODKEY|ControlMask,           XK_Right, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Left,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Right, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask|ControlMask, XK_e,      quit,           {0} },

    /* gap resizing */
    { MODKEY,                       XK_equal,  setgaps,       {.i = -1 } },
    { MODKEY,                       XK_minus,  setgaps,       {.i = +1 } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

