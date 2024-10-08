#include <main.hpp>
#include <action.hpp>

/* ************************************************************************** */
/*                                 ACTION.CPP                                 */
/* ************************************************************************** */

/* ****************************** BASIC ACTIONS ***************************** */
std::string	sendTransportMessage(std::string const action, int const buildingId1, int const buildingId2)
{
	std::string	result = action + " "; // can either be TUBE, UPGRADE or TELEPORT
	result += std::to_string(buildingId1) + " "; // TELEPORT action Entrance
	result += std::to_string(buildingId2) + ";"; // TELEPORT action Exit
	return (result);
}

std::string	createPod(int const podId, std::vector<int> const checkpoints)
{
	std::string	result = "POD " + std::to_string(podId) + " ";
	for (unsigned int i = 0; i < checkpoints.size(); i++)
	{
		if (i != checkpoints.size() - 1)
			result += std::to_string(checkpoints[i]) + " ";
		else
			result += std::to_string(checkpoints[i]) + ";";
	}
	return (result);
}

std::string	destroyPod(int const podId)
{
	std::string	result = "DESTROY " + std::to_string(podId) + ";";
	return (result);
}

/* ***************************** ACTION MODULES ***************************** */
std::string	createRoute(int const podId, int const buildingId1, int const buildingId2)
{
	std::string	result = sendTransportMessage("TUBE", buildingId1, buildingId2);
	std::vector<int>	checkpointList;
	for (int i = 0; i < MAX_POD_CHECKPOINT; i++)
	{
		if (i % 2 == 0)
			checkpointList.push_back(buildingId1);
		else
			checkpointList.push_back(buildingId2);
	}
	result += createPod(podId, checkpointList);
	return (result);
}