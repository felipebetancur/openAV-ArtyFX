// generated by Fast Light User Interface Designer (fluid) version 1.0300

#include "widget.h"

void PandaWidget::cb_headerImage_i(Avtk::Image*, void*) {
  //system("xdg-open http://www.openavproductions.com/artyfx#ducka");
}
void PandaWidget::cb_headerImage(Avtk::Image* o, void* v) {
  ((PandaWidget*)(o->parent()->user_data()))->cb_headerImage_i(o,v);
}

void PandaWidget::cb_graph_i(Avtk::Compander* o, void*) {
  float tmp = o->value();
factor->value( tmp );
writePort(PANDA_FACTOR, tmp);

threshold->value( ((Avtk::Compander*)o)->getThreshold() );

float a = o->getActive();
writePort(PANDA_ACTIVE, a);
}
void PandaWidget::cb_graph(Avtk::Compander* o, void* v) {
  ((PandaWidget*)(o->parent()->user_data()))->cb_graph_i(o,v);
}

void PandaWidget::cb_factor_i(Avtk::Dial* o, void*) {
  float tmp = o->value();
graph->value( tmp );
writePort(PANDA_FACTOR, tmp);
printf("%f\n",tmp);
}
void PandaWidget::cb_factor(Avtk::Dial* o, void* v) {
  ((PandaWidget*)(o->parent()->user_data()))->cb_factor_i(o,v);
}

void PandaWidget::cb_threshold_i(Avtk::Dial* o, void*) {
  float tmp = o->value();
graph->setThreshold( tmp );
writePort(PANDA_THRESHOLD, tmp);
printf("%f\n",tmp);
}
void PandaWidget::cb_threshold(Avtk::Dial* o, void* v) {
  ((PandaWidget*)(o->parent()->user_data()))->cb_threshold_i(o,v);
}

void PandaWidget::cb_release_i(Avtk::Dial* o, void*) {
  float tmp = o->value();
graph->setRelease( tmp );
writePort(PANDA_RELEASE, tmp);
printf("%f\n",tmp);
}
void PandaWidget::cb_release(Avtk::Dial* o, void* v) {
  ((PandaWidget*)(o->parent()->user_data()))->cb_release_i(o,v);
}

/**
   if the type of filter changes, this function will highlight the right button
*/
void PandaWidget::update_button(int button) {
}

PandaWidget::PandaWidget() {
  { Fl_Double_Window* o = window = new Fl_Double_Window(160, 220, "Panda");
    window->user_data((void*)(this));
    { headerImage = new Avtk::Image(0, 0, 160, 29, "header.png");
      headerImage->box(FL_NO_BOX);
      headerImage->color(FL_BACKGROUND_COLOR);
      headerImage->selection_color(FL_BACKGROUND_COLOR);
      headerImage->labeltype(FL_NORMAL_LABEL);
      headerImage->labelfont(0);
      headerImage->labelsize(14);
      headerImage->labelcolor((Fl_Color)20);
      headerImage->callback((Fl_Callback*)cb_headerImage);
      headerImage->align(Fl_Align(FL_ALIGN_CENTER));
      headerImage->when(FL_WHEN_RELEASE_ALWAYS);
      headerImage->setPixbuf(header.pixel_data,4);
    } // Avtk::Image* headerImage
    { graph = new Avtk::Compander(5, 36, 150, 126, "graph");
      graph->box(FL_UP_BOX);
      graph->color((Fl_Color)179);
      graph->selection_color(FL_INACTIVE_COLOR);
      graph->labeltype(FL_NO_LABEL);
      graph->labelfont(0);
      graph->labelsize(14);
      graph->labelcolor(FL_FOREGROUND_COLOR);
      graph->callback((Fl_Callback*)cb_graph);
      graph->align(Fl_Align(FL_ALIGN_BOTTOM));
      graph->when(FL_WHEN_CHANGED);
    } // Avtk::Compander* graph
    { factor = new Avtk::Dial(112, 167, 40, 40, "Factor");
      factor->box(FL_NO_BOX);
      factor->color((Fl_Color)90);
      factor->selection_color(FL_INACTIVE_COLOR);
      factor->labeltype(FL_NORMAL_LABEL);
      factor->labelfont(0);
      factor->labelsize(10);
      factor->labelcolor(FL_FOREGROUND_COLOR);
      factor->callback((Fl_Callback*)cb_factor);
      factor->align(Fl_Align(FL_ALIGN_BOTTOM));
      factor->when(FL_WHEN_CHANGED);
    } // Avtk::Dial* factor
    { threshold = new Avtk::Dial(10, 167, 40, 40, "Threshold");
      threshold->box(FL_NO_BOX);
      threshold->color((Fl_Color)90);
      threshold->selection_color(FL_INACTIVE_COLOR);
      threshold->labeltype(FL_NORMAL_LABEL);
      threshold->labelfont(0);
      threshold->labelsize(10);
      threshold->labelcolor(FL_FOREGROUND_COLOR);
      threshold->callback((Fl_Callback*)cb_threshold);
      threshold->align(Fl_Align(FL_ALIGN_BOTTOM));
      threshold->when(FL_WHEN_CHANGED);
    } // Avtk::Dial* threshold
    { release = new Avtk::Dial(62, 167, 40, 40, "Release");
      release->box(FL_NO_BOX);
      release->color((Fl_Color)90);
      release->selection_color(FL_INACTIVE_COLOR);
      release->labeltype(FL_NORMAL_LABEL);
      release->labelfont(0);
      release->labelsize(10);
      release->labelcolor(FL_FOREGROUND_COLOR);
      release->callback((Fl_Callback*)cb_release);
      release->align(Fl_Align(FL_ALIGN_BOTTOM));
      release->when(FL_WHEN_CHANGED);
    } // Avtk::Dial* release
    window->color( fl_rgb_color( 17, 17, 17) );
    close_cb( o, 0 );
    window->end();
  } // Fl_Double_Window* window
}

void PandaWidget::idle() {
  Fl::check();
  Fl::flush();
}

int PandaWidget::getWidth() {
  return window->w();
}

int PandaWidget::getHeight() {
  return window->h();
}

void PandaWidget::writePort(int port, float& value) {
  //cout << "port " << port << " value " << value << endl;
  write_function(controller, port, sizeof(float), 0, &value);
}

void PandaWidget::close_cb(Fl_Widget* o, void*) {
  if ((Fl::event() == FL_KEYDOWN || Fl::event() == FL_SHORTCUT) && Fl::event_key() == FL_Escape)
    {
      return; // ignore ESC
    }
    else
    {
      o->hide();
    }
}
