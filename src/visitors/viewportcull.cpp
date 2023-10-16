#include "visitors/viewportcull.h"

#include "nodes/drawablerect.h"
#include "nodes/collider.h"

ViewportCull::ViewportCull(Rect viewport):
    m_Viewport(viewport)
{
    m_Drawables = std::vector<DrawableRect*>();
}

ViewportCull::~ViewportCull()
{}

void ViewportCull::Visit(DrawableRect* rect)
{
    if (m_Viewport.Intersects(rect->Rectangle))
        m_Drawables.push_back(rect);
}

void ViewportCull::Visit(Collider* collider)
{
    Visit((DrawableRect*)collider);
}

std::vector<DrawableRect*> ViewportCull::GetDrawables() const
{
    return m_Drawables;
}