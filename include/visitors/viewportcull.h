#ifndef VIEWPORTCULL_H
#define VIEWPORTCULL_H

#include "visitor.h"
#include "maths/rect.h"

#include <vector>

class ViewportCull : public Visitor
{
public:
    ViewportCull(Rect viewport);
    ~ViewportCull();

    void Visit(const Node* node) override;
    void Visit(const DrawableRect* rect) override;
    void Visit(const Collider* collider) override;

    std::vector<const DrawableRect*> GetDrawables() const;

private:

    Rect m_Viewport;

    std::vector<const DrawableRect*> m_Drawables;
};

#endif // VIEWPORTCULL_H