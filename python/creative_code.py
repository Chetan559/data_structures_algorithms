import drawio.drawio as drawio

# Create a Draw.io diagram
diagram = drawio.Diagram()

# Add the central topic
diagram.add_shape(drawio.Shape(
    shape_id="1",
    shape_type="rectangle",
    fill_color="white",
    border_color="black",
    border_width=2,
    font_size=16,
    font_weight="bold",
    text="Rule-Based Expert Chatbot for Government Rules"
))

# Add the branches
branches = [
    "Purpose",
    "Problem Description",
    "Solutions/Viability of System",
    "Future Prospects",
    "Requirements Analysis"
]

for branch in branches:
    diagram.add_shape(drawio.Shape(
        shape_id=str(len(branches) + 1),
        shape_type="rectangle",
        fill_color="yellow",
        border_color="black",
        border_width=2,
        font_size=14,
        font_weight="normal",
        text=branch
    ))

# Add the sub-branches
sub_branches = {
    "Purpose": [
        "Information retrieval and dissemination",
        "Language translation and interpretation",
        "Legal assistance"
    ],
    "Problem Description": [
        "Complex and extensive rulebooks",
        "Time-consuming manual queries",
        "Inconsistent interpretations"
    ],
    "Solutions/Viability of System": [
        "Chatbot system to help and guide officers",
        "Smart and can understand and talk to users in different languages"
    ],
    "Future Prospects": [
        "More languages to be added",
        "Mobile app to be developed for iOS",
        "Real-time updates and alerts on changes in government rules",
        "Voice-based queries and multimodal interactions"
    ],
    "Requirements Analysis": [
        "Comprehensive knowledge base",
        "Rule engine",
        "Natural Language Processing (NLP) capabilities",
        "Decision logic",
        "Context management",
        "Error handling"
    ]
}

for branch, sub_branches in sub_branches.items():
    for sub_branch in sub_branches:
        diagram.add_shape(drawio.Shape(
            shape_id=str(len(sub_branches) + len(branches) + 1),
            shape_type="rectangle",
            fill_color="lightgreen",
            border_color="black",
            border_width=2,
            font_size=12,
            font_weight="normal",
            text=sub_branch
        ))

# Add the relationships
relationships = [
    ("1", "2"),
    ("1", "3"),
    ("1", "4"),
    ("1", "5"),
    ("2", "6"),
    ("2", "7"),
    ("2", "8"),
    ("3", "9"),
    ("3", "10"),
    ("4", "11"),
    ("4", "12"),
    ("4", "13"),
    ("4", "14"),
    ("5", "15"),
    ("5", "16"),
    ("5", "17"),
    ("5", "18")
]

for relationship in relationships:
    diagram.add_relationship(drawio.Relationship(
        source_shape_id=relationship[0],
        target_shape_id=relationship[1],
        shape_type="line",
        color="black",
        width=2
    ))

# Generate the mind map
diagram.generate_image("mind_map.png")
