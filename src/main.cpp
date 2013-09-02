/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.cc
 * Copyright (C) 2013 Paul <pfultz2@yahoo.com>
 * 
 * Cider is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Cider is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtkmm.h>
#include <iostream>
#include <fstream>
#include <gtksourceviewmm.h>
#include <cassert>
#include "config.h"


#ifdef ENABLE_NLS
#  include <libintl.h>
#endif


Glib::RefPtr<Gsv::Buffer> open_file(const char * filename)
{
    auto buffer = Gsv::Buffer::create();
    auto lm = Gsv::LanguageManager::create();
    auto lang = lm->guess_language(filename, Glib::ustring());
    buffer->set_highlight_syntax(true);
    buffer->set_language(lang);

    buffer->begin_not_undoable_action();
    std::vector<char> contents;
    std::ifstream fs(filename);
    std::copy(std::istreambuf_iterator<char>(fs), std::istreambuf_iterator<char>(), std::back_inserter(contents));
    buffer->set_text(&contents[0], &contents[0] + contents.size());
    buffer->end_not_undoable_action();
    
    buffer->set_modified(false);
    // buffer->place_cursor(buffer->get_start_iter());
    return buffer;
}

   
int
main (int argc, char *argv[])
{
    Gtk::Main kit(argc, argv);
    Gsv::init();
    auto buffer = open_file(argv[1]);
    assert(buffer);
    Gsv::View view(buffer);
    // view.set_source_buffer(buffer);
    
    Gtk::Window* main_win = new Gtk::Window (Gtk::WINDOW_TOPLEVEL);
    main_win->set_title ("Cider");
    main_win->add(view);
    main_win->show_all_children();

    if (main_win)
    {
        kit.run(*main_win);
    }
    return 0;
}

