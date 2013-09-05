#ifndef CIDER_MAIN_WINDOW_H
#define CIDER_MAIN_WINDOW_H


#include <gtkmm.h>
#include <gtksourceviewmm.h>

class main_window : public Gtk::Window
{
public:
  main_window();

  void open(const std::string& s);
protected:

  //Child widgets:
  Gtk::Box vbox;

  Gtk::ScrolledWindow scrolled_window;
  Gsv::View view;

  Glib::RefPtr<Gsv::Buffer> buffer;
  
};

#endif