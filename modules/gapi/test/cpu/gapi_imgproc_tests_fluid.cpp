// This file is part of OpenCV project.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://opencv.org/license.html.
//
// Copyright (C) 2018 Intel Corporation


#include "../test_precomp.hpp"
#include "../common/gapi_imgproc_tests.hpp"
#include "backends/fluid/gfluidimgproc.hpp"

#define IMGPROC_FLUID cv::gapi::imgproc::fluid::kernels()

namespace opencv_test
{

INSTANTIATE_TEST_CASE_P(RGB2GrayTestFluid, RGB2GrayTest,
                        Combine(Values(ToleranceRGBBGR(0.001).to_compare_f()),
                                Values(cv::Size(1280, 720),
                                cv::Size(640, 480)),
                                Values(true, false),
                                Values(cv::compile_args(IMGPROC_FLUID))));

INSTANTIATE_TEST_CASE_P(BGR2GrayTestFluid, BGR2GrayTest,
                        Combine(Values(ToleranceRGBBGR(0.001).to_compare_f()),
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
                                Values(true, false),
                                Values(cv::compile_args(IMGPROC_FLUID))));

INSTANTIATE_TEST_CASE_P(RGB2YUVTestFluid, RGB2YUVTest,
                        Combine(Values(ToleranceRGBBGR(0.15*3).to_compare_f()),
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
                                Values(true, false),
                                Values(cv::compile_args(IMGPROC_FLUID))));

INSTANTIATE_TEST_CASE_P(YUV2RGBTestFluid, YUV2RGBTest,
                        Combine(Values(ToleranceTriple(0.25 * 3, 0.01 * 3, 1e-5 * 3).to_compare_f()),
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
                                Values(true, false),
                                Values(cv::compile_args(IMGPROC_FLUID))));

INSTANTIATE_TEST_CASE_P(RGB2LabTestFluid, RGB2LabTest,
                        Combine(Values(ToleranceTriple(0.25 * 3, 0.0, 1e-5 * 3).to_compare_f()),
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
                                Values(true, false),
                                Values(cv::compile_args(IMGPROC_FLUID))));

// FIXME: Not supported by Fluid yet (no kernel implemented)
INSTANTIATE_TEST_CASE_P(BGR2LUVTestFluid, BGR2LUVTest,
                        Combine(Values(ToleranceTriple(0.25 * 3, 0.01 * 3, 0.0001 * 3).to_compare_f()),
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
                                Values(true, false),
                                Values(cv::compile_args(IMGPROC_FLUID))));

INSTANTIATE_TEST_CASE_P(blurTestFluid, BlurTest,
                        Combine(Values(AbsTolerance(0.0).to_compare_f()),
                                Values(CV_8UC1, CV_16UC1, CV_16SC1),
                                Values(3), // add kernel size=5 when implementation is ready
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
                                Values(cv::BORDER_DEFAULT),
                                Values(true, false),
                                Values(cv::compile_args(IMGPROC_FLUID))));

INSTANTIATE_TEST_CASE_P(gaussBlurTestFluid, GaussianBlurTest,
                        Combine(Values(AbsToleranceGaussianBlur_Float_Int(1e-6, 1e-6).to_compare_f()),
                                Values(CV_8UC1, CV_16UC1, CV_16SC1),
                                Values(3), // add kernel size=5 when implementation is ready
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
                                Values(true, false),
                                Values(cv::compile_args(IMGPROC_FLUID))));

INSTANTIATE_TEST_CASE_P(medianBlurTestFluid, MedianBlurTest,
                        Combine(Values(AbsExact().to_compare_f()),
                                Values(CV_8UC1, CV_16UC1, CV_16SC1),
                                Values(3), // add kernel size=5 when implementation is ready
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
                                Values(true, false),
                                Values(cv::compile_args(IMGPROC_FLUID))));

INSTANTIATE_TEST_CASE_P(erodeTestFluid, ErodeTest,
                        Combine(Values(AbsExact().to_compare_f()),
                                Values(CV_8UC1, CV_16UC1, CV_16SC1),
                                Values(3), // add kernel size=5 when implementation is ready
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
                                Values(cv::MorphShapes::MORPH_RECT,
                                       cv::MorphShapes::MORPH_CROSS,
                                       cv::MorphShapes::MORPH_ELLIPSE),
                                Values(true, false),
                                Values(cv::compile_args(IMGPROC_FLUID))));

INSTANTIATE_TEST_CASE_P(dilateTestFluid, DilateTest,
                        Combine(Values(AbsExact().to_compare_f()),
                                Values(CV_8UC1, CV_16UC1, CV_16SC1),
                                Values(3), // add kernel size=5 when implementation is ready
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
                                Values(cv::MorphShapes::MORPH_RECT,
                                       cv::MorphShapes::MORPH_CROSS,
                                       cv::MorphShapes::MORPH_ELLIPSE),
                                Values(true, false),
                                Values(cv::compile_args(IMGPROC_FLUID))));

INSTANTIATE_TEST_CASE_P(SobelTestFluid, SobelTest,
                        Combine(Values(AbsExact().to_compare_f()),
                                Values(CV_8UC1, CV_16UC1, CV_16SC1),
                                Values(3), // add kernel size=5 when implementation is ready
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
                                Values(-1, CV_32F),
                                Values(0, 1),
                                Values(1, 2),
                                Values(true, false),
                                Values(cv::compile_args(IMGPROC_FLUID))));

INSTANTIATE_TEST_CASE_P(SobelTestFluid32F, SobelTest,
                        Combine(Values(AbsToleranceSobel(1e-3).to_compare_f()),
                                Values(CV_32FC1),
                                Values(3), // add kernel size=5 when implementation is ready
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
                                Values(CV_32F),
                                Values(0, 1),
                                Values(1, 2),
                                Values(true, false),
                                Values(cv::compile_args(IMGPROC_FLUID))));

INSTANTIATE_TEST_CASE_P(boxFilterTestFluid32, BoxFilterTest,
                        Combine(Values(AbsTolerance_Float_Int(1e-6, 1e-4).to_compare_f()),
                                Values(CV_8UC1, CV_16UC1, CV_16SC1),
                                Values(3), // add kernel size=5 when implementation is ready
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
                                Values(cv::BORDER_DEFAULT),
                                Values(-1, CV_32F),
                                Values(true, false),
                                Values(cv::compile_args(IMGPROC_FLUID))));

INSTANTIATE_TEST_CASE_P(sepFilterTestFluid, SepFilterTest,
                        Combine(Values(AbsToleranceSepFilter(1e-5f).to_compare_f()),
                                Values(CV_32FC1),
                                Values(3), // add kernel size=5 when implementation is ready
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480)),
                                Values(-1, CV_32F),
                                Values(true, false),
                                Values(cv::compile_args(IMGPROC_FLUID))));

INSTANTIATE_TEST_CASE_P(filter2DTestFluid, Filter2DTest,
                        Combine(Values(AbsTolerance_Float_Int(1e-6, 1e-4).to_compare_f()),
                                Values(CV_8UC1, CV_16UC1, CV_16SC1),
                                Values(3), // add kernel size=4,5,7 when implementation ready
                                Values(cv::Size(1280, 720),
                                       cv::Size(640, 480),
                                       cv::Size(128, 128)),
                                Values(cv::BORDER_DEFAULT),
                                Values(-1, CV_32F),
                                Values(true, false),
                                Values(cv::compile_args(IMGPROC_FLUID))));

} // opencv_test
