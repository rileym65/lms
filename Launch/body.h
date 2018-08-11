#ifndef _BODY_H
#define _BODY_H

class Body {
  protected:
    char name[64];
    Double mass;
    Double radius;
    Double gravitation;
  public:
    Body(const char* n, Double m, Double r);
    ~Body();
    char  *Name();
    Double Gravitation();
    Double Mass();
    Double Radius();
  };

#endif

