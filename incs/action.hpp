#pragma once

/* ************************************************************************** */
/*                                 ACTION.HPP                                 */
/* ************************************************************************** */
std::string	sendTransportMessage(std::string const action, int const buildingId1, int const buildingId2);
std::string	createPod(int const podId, std::vector<int> const checkpoints);
std::string	destroyPod(int const podId);
std::string	createRoute(int const podId, int const buildingId1, int const buildingId2);