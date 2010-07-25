#ifndef SEEN_PREFERENCES_SKELETON_H
#define SEEN_PREFERENCES_SKELETON_H

#include <inkscape-version.h>

#ifdef N_
#undef N_
#endif
#define N_(x) x

/* The root's "version" attribute describes the preferences file format version.
 * It should only increase when a backwards-incompatible change is made,
 * and special handling has to be added to the preferences class to update
 * obsolete versions the user might have. */
static char const preferences_skeleton[] =
"<inkscape version=\"1\"\n"
"  xmlns:sodipodi=\"http://sodipodi.sourceforge.net/DTD/sodipodi-0.dtd\"\n"
"  xmlns:inkscape=\"http://www.inkscape.org/namespaces/inkscape\">\n"
"  <group id=\"window\">\n"
"    <group id=\"task\" />\n"
"    <group id=\"menu\" state=\"1\"/>\n"
"    <group id=\"commands\" state=\"1\"/>\n"
"    <group id=\"snaptoolbox\" state=\"1\"/>\n"
"    <group id=\"toppanel\" state=\"1\"/>\n"
"    <group id=\"toolbox\" state=\"1\"/>\n"
"    <group id=\"statusbar\" state=\"1\"/>\n"
"    <group id=\"panels\" state=\"1\"/>\n"
"    <group id=\"rulers\" state=\"1\"/>\n"
"    <group id=\"scrollbars\" state=\"1\"/>\n"
"  </group>\n"
"  <group id=\"fullscreen\">\n"
"    <group id=\"task\" />\n"
"    <group id=\"menu\" state=\"1\"/>\n"
"    <group id=\"commands\" state=\"1\"/>\n"
"    <group id=\"snaptoolbox\" state=\"1\"/>\n"
"    <group id=\"toppanel\" state=\"1\"/>\n"
"    <group id=\"toolbox\" state=\"1\"/>\n"
"    <group id=\"statusbar\" state=\"1\"/>\n"
"    <group id=\"panels\" state=\"1\"/>\n"
"    <group id=\"rulers\" state=\"1\"/>\n"
"    <group id=\"scrollbars\" state=\"1\"/>\n"
"  </group>\n"
"  <group id=\"focus\">\n"
"    <group id=\"task\" />\n"
"    <group id=\"menu\" state=\"0\"/>\n"
"    <group id=\"commands\" state=\"0\"/>\n"
"    <group id=\"snaptoolbox\" state=\"0\"/>\n"
"    <group id=\"toppanel\" state=\"0\"/>\n"
"    <group id=\"toolbox\" state=\"0\"/>\n"
"    <group id=\"statusbar\" state=\"0\"/>\n"
"    <group id=\"panels\" state=\"0\"/>\n"
"    <group id=\"rulers\" state=\"0\"/>\n"
"    <group id=\"scrollbars\" state=\"0\"/>\n"
"  </group>\n"
"\n"
"  <group id=\"documents\">\n"
"    <group id=\"recent\"/>\n"
"  </group>\n"
"\n"
"  <group id=\"template\">\n"
"    <sodipodi:namedview\n"
"       id=\"base\"\n"
"       pagecolor=\"#ffffff\"\n"
"       bordercolor=\"#666666\"\n"
"       borderopacity=\"1.0\"\n"
"       objecttolerance=\"10.0\"\n"
"       gridtolerance=\"10.0\"\n"
"       guidetolerance=\"10.0\"\n"
"       inkscape:pageopacity=\"0.0\"\n"
"       inkscape:pageshadow=\"2\"\n"
"       inkscape:window-width=\"640\"\n"
"       inkscape:window-height=\"480\" />\n"
"  </group>\n"
"\n"
"  <group id=\"tools\"\n"
"         bounding_box=\"0\"\n"
"         style=\"fill:none;stroke:black;stroke-opacity:1;stroke-width:1px;stroke-linejoin:miter;stroke-linecap:butt;\">\n"
"    <group id=\"shapes\" style=\"fill-rule:evenodd;\" selcue=\"1\" gradientdrag=\"1\">\n"
"      <eventcontext id=\"rect\" style=\"fill:blue;\" usecurrent=\"1\"/>\n"
"      <eventcontext id=\"3dbox\" style=\"stroke:none;stroke-linejoin:round;\" usecurrent=\"1\">\n"
"        <side id=\"XYfront\"  style=\"fill:#8686bf;stroke:none;stroke-linejoin:round;\" usecurrent=\"0\"/>\n"
"        <side id=\"XYrear\"   style=\"fill:#e9e9ff;stroke:none;stroke-linejoin:round;\" usecurrent=\"0\"/>\n"
"        <side id=\"XZtop\"    style=\"fill:#4d4d9f;stroke:none;stroke-linejoin:round;\" usecurrent=\"0\"/>\n"
"        <side id=\"XZbottom\" style=\"fill:#afafde;stroke:none;stroke-linejoin:round;\" usecurrent=\"0\"/>\n"
"        <side id=\"YZright\"  style=\"fill:#353564;stroke:none;stroke-linejoin:round;\" usecurrent=\"0\"/>\n"
"        <side id=\"YZleft\"   style=\"fill:#d7d7ff;stroke:none;stroke-linejoin:round;\" usecurrent=\"0\"/>\n"
"      </eventcontext>\n"
"      <eventcontext id=\"arc\" style=\"fill:red;\" end=\"0\" start=\"0\" usecurrent=\"1\"/>\n"
"      <eventcontext id=\"star\" magnitude=\"5\" style=\"fill:yellow;\" usecurrent=\"1\"/>\n"
"      <eventcontext id=\"spiral\" style=\"fill:none;\" usecurrent=\"0\"/>\n"
"    </group>\n"
"    <group id=\"freehand\"\n"
"         style=\"fill:none;fill-rule:evenodd;stroke:black;stroke-opacity:1;stroke-linejoin:miter;stroke-linecap:butt;\">\n"
"      <eventcontext id=\"pencil\" tolerance=\"4.0\" selcue=\"1\" style=\"stroke-width:1px;\" usecurrent=\"0\" average_all_sketches=\"1\"/>\n"
"      <eventcontext id=\"pen\" mode=\"drag\" selcue=\"1\" style=\"stroke-width:1px;\" usecurrent=\"0\"/>\n"
"    </group>\n"
"    <eventcontext id=\"calligraphic\" style=\"fill:black;fill-opacity:1;fill-rule:nonzero;stroke:none;\"\n"
"                       mass=\"2\" angle=\"30\" width=\"15\" thinning=\"10\" flatness=\"90\" cap_rounding=\"0.0\" usecurrent=\"1\"\n"
"                       tracebackground=\"0\" usepressure=\"1\" usetilt=\"0\" keep_selected=\"1\">\n"
"    <group id=\"preset\">\n"
"    <group id=\"cp0\" name=\"" N_("Dip pen") "\" mass=\"2\" wiggle=\"0.0\" angle=\"30.0\" thinning=\"10\" tremor=\"0.0\" flatness=\"90\" cap_rounding=\"0.0\" tracebackground=\"0\" usepressure=\"1\" usetilt=\"1\" />\n"
"    <group id=\"cp1\" name=\"" N_("Marker") "\" mass=\"2\" wiggle=\"0.0\" angle=\"90.0\" thinning=\"0.0\" tremor=\"0.0\" flatness=\"0.0\" cap_rounding=\"1.0\" tracebackground=\"0\" usepressure=\"0\" usetilt=\"0\" />\n"
"    <group id=\"cp2\" name=\"" N_("Brush") "\" mass=\"2\" wiggle=\"25\" angle=\"45.0\" thinning=\"-40\" tremor=\"0.0\" flatness=\"16\" cap_rounding=\".1\" tracebackground=\"0\" usepressure=\"1\" usetilt=\"1\" />\n"
"    <group id=\"cp3\" name=\"" N_("Wiggly") "\" usetilt=\"1\" tracebackground=\"0\" usepressure=\"1\" cap_rounding=\"0.1\" flatness=\"16\" tremor=\"18\" thinning=\"-30\" angle=\"30\" wiggle=\"50\" mass=\"0\" />\n"
"    <group id=\"cp4\" name=\"" N_("Splotchy") "\" width=\"100\" usetilt=\"1\" tracebackground=\"0\" usepressure=\"0\" cap_rounding=\"1\" flatness=\"0\" tremor=\"10\" thinning=\"30\" angle=\"30\" wiggle=\"0\" mass=\"0\" />\n"
"    <group id=\"cp5\" name=\"" N_("Tracing") "\" width=\"50\" mass=\"0\" wiggle=\"0.0\" angle=\"0.0\" thinning=\"0.0\" tremor=\"0.0\" flatness=\"0\" cap_rounding=\"0.0\" tracebackground=\"1\" usepressure=\"1\" usetilt=\"1\"/>\n"
"    </group>\n"
"    </eventcontext>\n"
"    <eventcontext id=\"eraser\" mode=\"0\" style=\"fill:#ff0000;fill-opacity:1;fill-rule:nonzero;stroke:none;\"\n"
"                       mass=\"0.02\" drag=\"1\" angle=\"30\" width=\"0.15\" thinning=\"0.1\" flatness=\"0.0\" cap_rounding=\"1.4\" usecurrent=\"0\"\n"
"                       tracebackground=\"0\" usepressure=\"1\" usetilt=\"0\" selcue=\"1\">\n"
"    </eventcontext>\n"
"    <eventcontext id=\"lpetool\" mode=\"drag\" style=\"fill:#ff0000;fill-opacity:1;fill-rule:nonzero;stroke:none;\">\n"
"    </eventcontext>\n"
"    <eventcontext id=\"text\"  usecurrent=\"0\" gradientdrag=\"1\"\n"
"                       font_sample=\"AaBbCcIiPpQq12369$\342\202\254\302\242?.;/()\"\n"
"                       show_sample_in_list=\"1\"\n"
"                  style=\"fill:black;fill-opacity:1;stroke:none;font-family:Sans;font-style:normal;font-weight:normal;font-size:40px;\" selcue=\"1\"/>\n"
"    <eventcontext id=\"nodes\" selcue=\"1\" gradientdrag=\"1\" highlight_color=\"4278190335\" pathflash_enabled=\"1\" pathflash_unselected=\"0\" pathflash_timeout=\"500\" show_handles=\"1\" show_outline=\"0\" sculpting_profile=\"1\" single_node_transform_handles=\"0\" show_transform_handles=\"0\" live_outline=\"1\" live_objects=\"1\" show_helperpath=\"0\" x=\"0\" y=\"0\" edit_clipping_paths=\"0\" edit_masks=\"0\" />\n"
"    <eventcontext id=\"tweak\" selcue=\"0\" gradientdrag=\"0\" show_handles=\"0\" width=\"0.2\" force=\"0.2\" fidelity=\"0.5\" usepressure=\"1\" style=\"fill:red;stroke:none;\" usecurrent=\"0\"/>\n"
"    <eventcontext id=\"spray\" usepressure=\"1\" width=\"15\" population=\"70\" mode=\"1\" rotation_variation=\"0\" scale_variation=\"0\" standard_deviation=\"70\" mean=\"0\"/>\n"
"    <eventcontext id=\"gradient\" selcue=\"1\"/>\n"
"    <eventcontext id=\"zoom\" selcue=\"1\" gradientdrag=\"0\"/>\n"
"    <eventcontext id=\"dropper\" selcue=\"1\" gradientdrag=\"1\" pick=\"1\" setalpha=\"1\"/>\n"
"    <eventcontext id=\"select\" selcue=\"1\" gradientdrag=\"0\"/>\n"
"    <eventcontext id=\"connector\" style=\"fill:none;fill-rule:evenodd;stroke:black;stroke-opacity:1;stroke-linejoin:miter;stroke-width:1px;stroke-linecap:butt;\" selcue=\"1\"/>\n"
"    <eventcontext id=\"paintbucket\" style=\"fill:#a0a0a0;stroke:none;\" usecurrent=\"1\"/>\n"
"  </group>\n"
"  <group id=\"palette\">\n"
"    <group id=\"dashes\">\n"
"      <dash id=\"solid\" style=\"stroke-dasharray:none\"/>\n"
"      <dash id=\"dash-1-1\" style=\"stroke-dasharray:1,1\"/>\n"
"      <dash id=\"dash-1-2\" style=\"stroke-dasharray:1,2\"/>\n"
"      <dash id=\"dash-1-3\" style=\"stroke-dasharray:1,3\"/>\n"
"      <dash id=\"dash-1-4\" style=\"stroke-dasharray:1,4\"/>\n"
"      <dash id=\"dash-1-6\" style=\"stroke-dasharray:1,6\"/>\n"
"      <dash id=\"dash-1-8\" style=\"stroke-dasharray:1,8\"/>\n"
"      <dash id=\"dash-1-12\" style=\"stroke-dasharray:1,12\"/>\n"
"      <dash id=\"dash-1-24\" style=\"stroke-dasharray:1,24\"/>\n"
"      <dash id=\"dash-1-48\" style=\"stroke-dasharray:1,48\"/>\n"
"      <dash id=\"dash-2-1\" style=\"stroke-dasharray:2,1\"/>\n"
"      <dash id=\"dash-3-1\" style=\"stroke-dasharray:3,1\"/>\n"
"      <dash id=\"dash-4-1\" style=\"stroke-dasharray:4,1\"/>\n"
"      <dash id=\"dash-6-1\" style=\"stroke-dasharray:6,1\"/>\n"
"      <dash id=\"dash-8-1\" style=\"stroke-dasharray:8,1\"/>\n"
"      <dash id=\"dash-12-1\" style=\"stroke-dasharray:12,1\"/>\n"
"      <dash id=\"dash-24-1\" style=\"stroke-dasharray:24,1\"/>\n"
"      <dash id=\"dash-2-2\" style=\"stroke-dasharray:2,2\"/>\n"
"      <dash id=\"dash-3-3\" style=\"stroke-dasharray:3,3\"/>\n"
"      <dash id=\"dash-4-4\" style=\"stroke-dasharray:4,4\"/>\n"
"      <dash id=\"dash-6-6\" style=\"stroke-dasharray:6,6\"/>\n"
"      <dash id=\"dash-8-8\" style=\"stroke-dasharray:8,8\"/>\n"
"      <dash id=\"dash-12-12\" style=\"stroke-dasharray:12,12\"/>\n"
"      <dash id=\"dash-24-24\" style=\"stroke-dasharray:24,24\"/>\n"
"      <dash id=\"dash-2-4\" style=\"stroke-dasharray:2,4\"/>\n"
"      <dash id=\"dash-4-2\" style=\"stroke-dasharray:4,2\"/>\n"
"      <dash id=\"dash-2-6\" style=\"stroke-dasharray:2,6\"/>\n"
"      <dash id=\"dash-6-2\" style=\"stroke-dasharray:6,2\"/>\n"
"      <dash id=\"dash-4-8\" style=\"stroke-dasharray:4,8\"/>\n"
"      <dash id=\"dash-8-4\" style=\"stroke-dasharray:8,4\"/>\n"
"      <dash id=\"dash-2-1-012-1\" style=\"stroke-dasharray:2,1,0.5,1\"/>\n"
"      <dash id=\"dash-4-2-1-2\" style=\"stroke-dasharray:4,2,1,2\"/>\n"
"      <dash id=\"dash-8-2-1-2\" style=\"stroke-dasharray:8,2,1,2\"/>\n"
"      <dash id=\"dash-012-012\" style=\"stroke-dasharray:0.5,0.5\"/>\n"
"      <dash id=\"dash-014-014\" style=\"stroke-dasharray:0.25,0.25\"/>\n"
"      <dash id=\"dash-0110-0110\" style=\"stroke-dasharray:0.1,0.1\"/>\n"
"    </group>\n"
"  </group>\n"
"  <group id=\"colorselector\" page=\"0\"/>\n"
"  <group id=\"embedded\">\n"
"    <group id=\"swatches\"\n"
"      panel_size=\"1\"\n"
"      panel_mode=\"1\"\n"
"      panel_ratio=\"100\"\n"
"      panel_wrap=\"0\"\n"
"      palette=\"Inkscape default\" />\n"
"  </group>\n"
"  <group id=\"dialogs\">\n"
"    <group id=\"toolbox\"/>\n"
"    <group id=\"fillstroke\"/>\n"
"    <group id=\"filtereffects\"/>\n"
"    <group id=\"textandfont\"/>\n"
"    <group id=\"transformation\" applyseparately=\"0\"/>\n"
"    <group id=\"align\"/>\n"
"    <group id=\"xml\"/>\n"
"    <group id=\"find\"/>\n"
"    <group id=\"spellcheck\" w=\"200\" h=\"250\" lang=\"en_US\" ignorenumbers=\"1\"/>\n"
"    <group id=\"documentoptions\" state=\"1\"/>\n"
"    <group id=\"preferences\" state=\"1\"/>\n"
"    <group id=\"gradienteditor\"/>\n"
"    <group id=\"object\"/>\n"
"    <group id=\"export\" default=\"\" append_extension=\"1\" path=\"\">\n"
"      <group id=\"exportarea\"/>\n"
"      <group id=\"defaultxdpi\"/>\n"
"    </group>\n"
"    <group id=\"save_as\" default=\"\" append_extension=\"1\" enable_preview=\"1\" path=\"\" use_current_dir=\"1\"/>\n"
"    <group id=\"save_copy\" default=\"\" append_extension=\"1\" enable_preview=\"1\" path=\"\"/>\n"
"    <group id=\"open\" enable_preview=\"1\" path=\"\"/>\n"
"    <group id=\"import\" enable_preview=\"1\" path=\"\"/>\n"
"    <group id=\"debug\" redirect=\"0\"/>\n"
"    <group id=\"clonetiler\" />\n"
"    <group id=\"gridtiler\" />\n"
"    <group id=\"extension-error\" show-on-startup=\"0\"/>\n"
"    <group id=\"memory\" />\n"
"    <group id=\"messages\" />\n"
"    <group id=\"swatches\" />\n"
"    <group id=\"iconpreview\" />\n"
"    <group id=\"aboutextensions\" />\n"
"    <group id=\"treeeditor\" />\n"
"    <group id=\"layers\" maxDepth=\"20\"/>\n"
"    <group id=\"extensioneditor\" />\n"
"    <group id=\"trace\" state=\"1\" />\n"
"    <group id=\"script\" />\n"
"    <group id=\"input\" />\n"
"    <group id=\"colorpickerwindow\" />\n"
"    <group id=\"undo-history\" />\n"
"    <group id=\"filtereffects\" />\n"
"    <group id=\"transparency\"\n"
"       on-focus=\"1.0\"\n"
"       on-blur=\"0.50\"\n"
#ifdef WIN32
"       animate-time=\"0\"\n" // apparently windows sucks (flickers)
#else
"       animate-time=\"100\"\n" // time to change in ms
#endif
"      />\n"
"  </group>\n"
"  <group id=\"printing\">\n"
"    <settings id=\"ps\"/>\n"
"    <group id=\"debug\" add-label-comments=\"0\"/>\n"
"  </group>\n"
"\n"
"  <group id=\"options\">\n"
"    <group id=\"useoldpdfexporter\" value=\"0\" />"
"    <group id=\"highlightoriginal\" value=\"1\" />"
"    <group id=\"relinkclonesonduplicate\" value=\"0\" />"
"    <group id=\"mapalt\" value=\"1\" />"
"    <group id=\"trackalt\" value=\"0\" />"
"    <group id=\"switchonextinput\" value=\"0\" />"
"    <group id=\"useextinput\" value=\"1\" />"
"    <group id=\"nudgedistance\" value=\"2\"/>\n"
"    <group id=\"rotationsnapsperpi\" value=\"12\"/>\n"
"    <group id=\"cursortolerance\" value=\"8.0\"/>\n"
"    <group id=\"dragtolerance\" value=\"4.0\"/>\n"
"    <group\n"
"       id=\"displayprofile\"\n"
"       enable=\"0\"\n"
"       from_display=\"0\"\n"
"       intent=\"0\"\n"
"       uri=\"\" />\n"
"    <group\n"
"       id=\"softproof\"\n"
"       enable=\"0\"\n"
"       intent=\"0\"\n"
"       gamutcolor=\"#808080\"\n"
"       gamutwarn=\"0\"\n"
"       bpc=\"0\"\n"
"       preserveblack=\"0\"\n"
"       uri=\"\" />\n"
"    <group id=\"savewindowgeometry\" value=\"1\"/>\n"
"    <group id=\"defaultoffsetwidth\" value=\"2\"/>\n"
"    <group id=\"defaultscale\" value=\"2\"/>\n"
"    <group id=\"maxrecentdocuments\" value=\"36\"/>\n"
"    <group id=\"zoomincrement\" value=\"1.414213562\"/>\n"
"    <group id=\"zoomcorrection\" value=\"1.0\" unit=\"mm\"/>\n"
"    <group id=\"keyscroll\" value=\"15\"/>\n"
"    <group id=\"wheelscroll\" value=\"40\"/>\n"
"    <group id=\"spacepans\" value=\"0\"/>\n"
"    <group id=\"wheelzooms\" value=\"0\"/>\n"
"    <group id=\"transientpolicy\" value=\"1\"/>\n"
"    <group id=\"scrollingacceleration\" value=\"0.4\"/>\n"
"    <group id=\"snapdelay\" value=\"150\"/>\n"
"    <group id=\"snapweight\" value=\"0.5\"/>\n"
"    <group id=\"snapclosestonly\" value=\"0\"/>\n"
"    <group id=\"snapindicator\" value=\"1\"/>\n"
"    <group id=\"autoscrollspeed\" value=\"0.7\"/>\n"
"    <group id=\"autoscrolldistance\" value=\"-10\"/>\n"
"    <group id=\"simplifythreshold\" value=\"0.002\"/>\n"
"    <group id=\"bitmapoversample\" value=\"1\"/>\n"
"    <group id=\"bitmapeditor\" value=\"0\" choices=\"gimp,krita,gpaint,kolourpaint,mtpaint,cinepaint\"/>\n"
"    <group id=\"bitmapautoreload\" value=\"1\"/>\n"
"    <group id=\"dialogtype\" value=\"1\"/>\n"
"    <group id=\"dock\" "
"           cancenterdock=\"1\""
"           dockbarstyle=\"2\""      // GDL_DOCK_BAR_BOTH
"           switcherstyle=\"2\"/>\n" // GDL_SWITCHER_STYLE_BOTH
"    <group id=\"dialogsskiptaskbar\" value=\"1\"/>\n"
#ifdef WIN32 // FIXME: Temporary Win32 special code to enable transient dialogs
"    <group id=\"dialogsontopwin32\" value=\"0\"/>\n"
#endif
"    <group id=\"arenatilescachesize\" value=\"8192\"/>\n"
"    <group id=\"preservetransform\" value=\"0\"/>\n"
"    <group id=\"clonecompensation\" value=\"1\"/>\n"
"    <group id=\"cloneorphans\" value=\"0\"/>\n"
"    <group id=\"stickyzoom\" value=\"0\"/>\n"
"    <group id=\"selcue\" value=\"2\"/>\n"
"    <group id=\"transform\" stroke=\"1\" rectcorners=\"1\" pattern=\"1\" gradient=\"1\" />\n"
"    <group id=\"kbselection\" inlayer=\"1\" onlyvisible=\"1\" onlysensitive=\"1\" />\n"
"    <group id=\"selection\" layerdeselect=\"1\" />\n"
"    <group id=\"createbitmap\"/>\n"
"    <group id=\"compassangledisplay\" value=\"0\"/>\n"
"    <group id=\"maskobject\" topmost=\"1\" remove=\"1\"/>\n"
"    <group id=\"blurquality\" value=\"0\"/>\n"
"    <group id=\"filterquality\" value=\"1\"/>\n"
"    <group id=\"showfiltersinfobox\" value=\"1\" />\n"
"    <group id=\"startmode\" outline=\"0\"/>\n"
"    <group id=\"outlinemode\" value=\"0\"/>\n"
"    <group id=\"ocalurl\" str=\"openclipart.org\"/>\n"
"    <group id=\"ocalusername\" str=\"\"/>\n"
"    <group id=\"ocalpassword\" str=\"\"/>\n"
"    <group id=\"wireframecolors\" "
"           onlight=\"255\"" // 000000ff
"           ondark=\"4294967295\"" //ffffffff
"           images=\"4278190335\"" //ff0000ff
"           clips=\"16711935\"" // 00ff00ff
"           masks=\"65535\"/>\n" // 0x0000ffff
"    <group id=\"svgoutput\" usenamedcolors=\"0\" numericprecision=\"8\" minimumexponent=\"-8\" inlineattrs=\"0\" indent=\"2\" allowrelativecoordinates=\"1\" forcerepeatcommands=\"0\"/>\n"
"    <group id=\"forkgradientvectors\" value=\"1\"/>\n"
"    <group id=\"iconrender\" named_nodelay=\"0\"/>\n"
"    <group id=\"autosave\" enable=\"0\" interval=\"10\" path=\"\" max=\"10\"/>\n"
"    <group id=\"grids\""
"      no_emphasize_when_zoomedout=\"0\">\n"
"      <group id=\"xy\" "
"             units=\"px\"\n"
"             origin_x=\"0.0\"\n"
"             origin_y=\"0.0\"\n"
"             spacing_x=\"1.0\"\n"
"             spacing_y=\"1.0\"\n"
"             color=\"65312\"\n"  // 0x0000FF20
"             empcolor=\"65344\"\n" // 0x0000FF40
"             empspacing=\"5\"\n"
"             dotted=\"0\"/>\n"
"      <group id=\"axonom\" "
"             units=\"mm\"\n"
"             origin_x=\"0.0\"\n"
"             origin_y=\"0.0\"\n"
"             spacing_y=\"1.0\"\n"
"             angle_x=\"30.0\"\n"
"             angle_z=\"30.0\"\n"
"             color=\"65312\"\n"  // 0x0000FF20
"             empcolor=\"65344\"\n" // 0x0000FF40
"             empspacing=\"5\"/>\n"
"    </group>\n"
"    <group id=\"workarounds\"\n"
"           colorsontop=\"0\"\n"
"           floatallowed=\"0\"\n"
"           partialdynamic=\"0\"/>\n"
"    <group id=\"threading\" numthreads=\"1\"/>\n"
"  </group>\n"
"\n"
"  <group id=\"extensions\">"
// NOTE: This gets filled in by the extensions themselves based on
// the properties that they provide in their INX files.
"  </group>\n"
"\n"
"  <group id=\"desktop\""
"         style=\"\">\n"
"    <group\n"
"       width=\"640\"\n"
"       height=\"480\"\n"
"       x=\"0\"\n"
"       y=\"0\"\n"
"       fullscreen=\"0\"\n"
"       id=\"geometry\" />\n"
"    <group\n"
"       id=\"XYfront\" />\n"
"    <group\n"
"       id=\"XYrear\" />\n"
"    <group\n"
"       id=\"XZtop\" />\n"
"    <group\n"
"       id=\"XZbottom\" />\n"
"    <group\n"
"       id=\"YZleft\" />\n"
"    <group\n"
"       id=\"YZright\" />\n"
"  </group>\n"
"\n"
"  <group id=\"devices\">\n"
"  </group>\n"
"\n"
"  <group\n"
"     id=\"toolbox\"\n"
"     icononly=\"1\"\n"
"     secondary=\"1\"\n"
"     small=\"1\">\n"
"    <group\n"
"       id=\"tools\"\n"
"       icononly=\"1\"\n"
"       small=\"0\" />\n"
"  </group>\n"
"\n"
"  <group\n"
"     id=\"iconpreview\"\n"
"     pack=\"1\"\n"
"     selectionHold=\"1\"\n"
"     showFrames=\"1\"\n"
"     selectionOnly=\"0\">\n"
"    <group\n"
"       id=\"sizes\">\n"
"      <group\n"
"         id=\"default\">\n"
"        <group\n"
"           value=\"16\"\n"
"           show=\"1\"\n"
"           id=\"size16\" />\n"
"        <group\n"
"           value=\"22\"\n"
"           show=\"0\"\n"
"           id=\"size22\" />\n"
"        <group\n"
"           value=\"24\"\n"
"           show=\"1\"\n"
"           id=\"size24\" />\n"
"        <group\n"
"           value=\"32\"\n"
"           show=\"1\"\n"
"           id=\"size32\" />\n"
"        <group\n"
"           value=\"48\"\n"
"           show=\"1\"\n"
"           id=\"size48\" />\n"
"        <group\n"
"           value=\"50\"\n"
"           show=\"0\"\n"
"           id=\"size50\" />\n"
"        <group\n"
"           value=\"64\"\n"
"           show=\"0\"\n"
"           id=\"size64\" />\n"
"        <group\n"
"           value=\"72\"\n"
"           show=\"0\"\n"
"           id=\"size72\" />\n"
"        <group\n"
"           value=\"80\"\n"
"           show=\"0\"\n"
"           id=\"size80\" />\n"
"        <group\n"
"           value=\"96\"\n"
"           show=\"0\"\n"
"           id=\"size96\" />\n"
"        <group\n"
"           value=\"128\"\n"
"           show=\"1\"\n"
"           id=\"size128\" />\n"
"        <group\n"
"           value=\"256\"\n"
"           show=\"0\"\n"
"           id=\"size256\" />\n"
"      </group>\n"
"    </group>\n"
"  </group>\n"
"  <group id = \"whiteboard\">\n"
"    <group id = \"server\" name = \"jabber.org\" port = \"5222\" username = \"\" ssl = \"0\"/>\n"
"    <group id = \"room\" name = \"inkboard\" server = \"gristle.org\"/>\n"
"  </group>\n"
"  <group id=\"debug\">\n"
"    <group id=\"latency\" skew=\"1\"/>\n"
"  </group>\n"
"  <group id=\"ui\"\n"
"    language=\"\"/>\n"
"\n"
"</inkscape>\n";

#define PREFERENCES_SKELETON_SIZE (sizeof(preferences_skeleton) - 1)


#endif /* !SEEN_PREFERENCES_SKELETON_H */

/*
  Local Variables:
  mode:c++
  c-file-style:"stroustrup"
  c-file-offsets:((innamespace . 0)(inline-open . 0)(case-label . +))
  indent-tabs-mode:nil
  fill-column:99
  End:
*/
// vim: filetype=cpp:expandtab:shiftwidth=4:tabstop=8:softtabstop=4:encoding=utf-8:textwidth=99 :
