import mindmaps.mindmap as mindmaps

# Create a new mind map
mind_map = mindmaps.MindMap("Chatbot for Government Officers")

# Add the main topic
main_topic = mind_map.add_node("Chatbot for Government Officers")

# Add the branches
branch1 = mind_map.add_node("Features", parent=main_topic)
branch2 = mind_map.add_node("Future Prospects", parent=main_topic)
branch3 = mind_map.add_node("Requirements", parent=main_topic)

# Add the sub-branches
branch1_1 = mind_map.add_node("Multi-lingual", parent=branch1)
branch1_2 = mind_map.add_node("Real-time updates", parent=branch1)
branch1_3 = mind_map.add_node("Voice-based queries", parent=branch1)

branch2_1 = mind_map.add_node("More languages", parent=branch2)
branch2_2 = mind_map.add_node("Android app", parent=branch2)
branch2_3 = mind_map.add_node("iOS app", parent=branch2)

branch3_1 = mind_map.add_node("Knowledge base", parent=branch3)
branch3_2 = mind_map.add_node("Rule engine", parent=branch3)
branch3_3 = mind_map.add_node("Natural language processing", parent=branch3)
branch3_4 = mind_map.add_node("Decision logic", parent=branch3)
branch3_5 = mind_map.add_node("Context management", parent=branch3)
branch3_6 = mind_map.add_node("Error handling", parent=branch3)

# Save the mind map
mind_map.save("chatbot_for_government_officers.mmap")

# Print the mind map
print(mind_map)

# Libraries to install
# - mindmaps: pip install mindmaps
