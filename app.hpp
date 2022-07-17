#pragma once

#include "pipeline.hpp"
#include "window.hpp"
#include "lve_device.hpp"
#include "lve_swap_chain.hpp"


#include <memory>
#include<vector>
namespace lve {
class FirstApp {
 public:
  static constexpr int WIDTH = 800;
  static constexpr int HEIGHT = 600;

  FirstApp();
  ~FirstApp();

  FirstApp(const FirstApp &) = delete;
  FirstApp &operator=(const FirstApp &) = delete;

  void run();

 private:
  void createPipelineLayout();
  void createPipeline();
  void createCommandBuffers();
  void drawFrame();

  LveWindow lveWindow{WIDTH, HEIGHT, "L-systems"};
  LveDevice lveDevice{lveWindow};
  LveSwapChain lveSwapChain{lveDevice, lveWindow.getExtent()};
  std::unique_ptr<LvePipeline> lvePipeline;
  VkPipelineLayout pipelineLayout;
  std::vector<VkCommandBuffer> commandBuffers;
};

}  // namespace lve