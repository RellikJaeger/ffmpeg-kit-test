/*
 * Copyright (c) 2022 Taner Sener
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "Application.h"
#include "MediaInformationParserTest.h"
#include "FFmpegKitTest.h"
#include <FFmpegKitConfig.h>

int main(int argc, char** argv) {
    auto app = Gtk::Application::create(argc, argv, "com.arthenica.ffmpegkit");
    ffmpegkittest::Application application;
    application.set_default_icon_name("ffmpeg-kit-linux-test");
    application.set_icon_name("ffmpeg-kit-linux-test");

    // RUN UNIT TESTS BEFORE STARTING THE APPLICATION
    testMediaInformationJsonParser();
    testFFmpegKit();

    app->run(application);
    ffmpegkit::FFmpegKitConfig::disableRedirection();
    app->quit();
    return 0;
}
