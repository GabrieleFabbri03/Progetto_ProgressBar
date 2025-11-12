#ifndef PROGETTO_PROGRESSBAR_OBSERVER_H
#define PROGETTO_PROGRESSBAR_OBSERVER_H

//classe che osserva la observable

class Observer {
public:
    virtual void updateProgress (float progress) = 0;
    virtual ~Observer() = default ;
};
#endif
