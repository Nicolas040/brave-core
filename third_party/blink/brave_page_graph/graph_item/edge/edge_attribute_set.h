/* Copyright (c) 2019 The Brave Software Team. Distributed under the MPL2
 * license. This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_BRAVE_PAGE_GRAPH_GRAPH_ITEM_EDGE_EDGE_ATTRIBUTE_SET_H_
#define BRAVE_COMPONENTS_BRAVE_PAGE_GRAPH_GRAPH_ITEM_EDGE_EDGE_ATTRIBUTE_SET_H_

#include <string>
#include "brave/third_party/blink/brave_page_graph/graph_item/edge.h"
#include "brave/third_party/blink/brave_page_graph/graph_item/edge/edge_attribute.h"
#include "brave/third_party/blink/brave_page_graph/types.h"

namespace brave_page_graph {

class Node;
class NodeActor;
class NodeHTMLElement;
class PageGraph;

class EdgeAttributeSet final : public EdgeAttribute {
friend class PageGraph;
 public:
  EdgeAttributeSet() = delete;
  ~EdgeAttributeSet() override;
  ItemName GetItemName() const override;
  const std::string& AttributeValue() const;

 protected:
  EdgeAttributeSet(PageGraph* const graph, const NodeActor* const out_node,
    const NodeHTMLElement* const in_node, const std::string& name,
    const std::string& value, const bool is_style = false);
  ItemDesc GetDescBody() const override;
  GraphMLXMLList GraphMLAttributes() const override;

  const std::string value_;
};

}  // namespace brave_page_graph

#endif  // BRAVE_COMPONENTS_BRAVE_PAGE_GRAPH_GRAPH_ITEM_EDGE_EDGE_ATTRIBUTE_SET_H_