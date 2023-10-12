#include "visitors/viewportcull.h"

#include "nodes/drawablerect.h"
#include "nodes/collider.h"

ViewportCull::ViewportCull(Rect viewport):
    m_Viewport(viewport)
{
    m_Drawables = std::vector<const DrawableRect*>();
}

ViewportCull::~ViewportCull()
{}

void ViewportCull::Visit(const DrawableRect* rect)
{
    if (m_Viewport.Intersects(rect->Rectangle))
        m_Drawables.push_back(rect);
}

void ViewportCull::Visit(const Collider* collider)
{
    Visit((DrawableRect*)collider);
}

std::vector<const DrawableRect*> ViewportCull::GetDrawables() const
{
    return m_Drawables;
}