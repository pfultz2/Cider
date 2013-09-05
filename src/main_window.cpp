
#include "main_window.h"

#include <iostream>
#include <fstream>
main_window::main_window()
: vbox(Gtk::ORIENTATION_VERTICAL)
{
  set_title("Gtk::TextView example");
  set_border_width(5);
  set_default_size(400, 200);


  this->add(this->vbox);

  
  this->scrolled_window.add(this->view);

  //Only show the scrollbars when they are necessary:
  this->scrolled_window.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

  this->vbox.pack_start(this->scrolled_window);

  show_all_children();
}

void main_window::open(const std::string& filename)
{
    this->buffer = Gsv::Buffer::create();
    auto lm = Gsv::LanguageManager::create();
    auto lang = lm->guess_language(filename, Glib::ustring());
    this->buffer->set_highlight_syntax(true);
    this->buffer->set_language(lang);

    this->buffer->begin_not_undoable_action();
    std::vector<char> contents;
    std::ifstream fs(filename);
    std::copy(std::istreambuf_iterator<char>(fs), std::istreambuf_iterator<char>(), std::back_inserter(contents));
    this->buffer->set_text(&contents[0], &contents[0] + contents.size());
    this->buffer->end_not_undoable_action();
    
    this->buffer->set_modified(false);
    this->view.set_buffer(this->buffer);
    // this->buffer->place_cursor(this->buffer->get_start_iter());
}
