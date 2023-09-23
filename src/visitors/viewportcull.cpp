#include "visitors/viewportcull.h"
#include "nodes/drawablerect.h"

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

void ViewportCull::Visit(const Node* node)
{
    (void)node;
}

std::vector<const DrawableRect*> ViewportCull::GetDrawables() const
{
    return m_Drawables;
}