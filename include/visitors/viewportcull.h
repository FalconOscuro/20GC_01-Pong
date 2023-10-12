#ifndef VIEWPORTCULL_H
#define VIEWPORTCULL_H

#include "visitor.h"
#include "maths/rect.h"

#include <vector>

/// @brief Visitor made to retrieve list of drawable nodes currently within the viewport
class ViewportCull : public Visitor
{
public:
    ViewportCull(Rect viewport);
    ~ViewportCull();

    void Visit(const DrawableRect* rect) override;
    void Visit(const Collider* collider) override;

    /// @brief Get list of all found visible drawables
    std::vector<const DrawableRect*> GetDrawables() const;

private:

    Rect m_Viewport;

    std::vector<const DrawableRect*> m_Drawables;
}; // class ViewportCull

#endif // VIEWPORTCULL_H